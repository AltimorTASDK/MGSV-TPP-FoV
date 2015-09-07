////////////////////////////////////////////////////////////////////////////////
//     ______ __  __ ______ __ __    __ __ ____   _   __ ___     __  ___ ____ //
//    / ____// / / // ____// //_/   / //_// __ \ / | / //   |   /  |/  //  _/ //
//   / /_   / / / // /    / ,<     / ,<  / / / //  |/ // /| |  / /|_/ / / /   //
//  / __/  / /_/ // /___ / /| |   / /| |/ /_/ // /|  // ___ | / /  / /_/ /    //
// /_/     \____/ \____//_/ |_|  /_/ |_|\____//_/ |_//_/  |_|/_/  /_//___/    //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <Windows.h>
#include <Psapi.h>

/**
 * get_module_bounds - Get the boundaries of a module
 * @name:	Name of module
 * @start:	Pointer to copy start of module bounds to
 * @end:	Pointer to copy end of module bounds to
 *
 * Get the module handle and use GetModuleInformation to get its bounds
 */
void get_module_bounds(const char *name, uintptr_t *start, uintptr_t *end)
{
	const auto module = GetModuleHandle(name);
	if(module == nullptr)
		return;

	MODULEINFO info;
	GetModuleInformation(GetCurrentProcess(), module, &info, sizeof(info));
	*start = (uintptr_t)(info.lpBaseOfDll);
	*end = *start + info.SizeOfImage;
}

/**
 * sigscan - Scan for a code pattern
 * @name:	Name of module to scan
 * @sig:	Byte sequence to scan for
 * @mask:	Wildcard mask, ?s will make the corresponding index in sig be
 *		ignored
 *
 * Check if the pattern matches starting at each byte from start to end. Will
 * throw an exception if the signature isn't found.
 */
uintptr_t sigscan(const char *name, const char *sig, const char *mask)
{
	uintptr_t start, end;
	get_module_bounds(name, &start, &end);

	const auto last_scan = end - strlen(mask) + 1;
	for (auto addr = start; addr < last_scan; addr++) {
		for (size_t i = 0;; i++) {
			if (mask[i] == '\0')
				return addr;
			if (mask[i] != '?' && sig[i] != *(char*)(addr + i))
				break;
		}
	}
	throw std::runtime_error("Sigscan failed");
}

// FOV is in focal length of a 24mm x 36mm camera lens and is locked horizontally
float new_tpp_fov, new_shoulder_fov, new_hiding_fov, new_cqc_fov;
constexpr auto default_tpp_fov      = 21.F;
constexpr auto default_shoulder_fov = 22.F;
constexpr auto default_hiding_fov   = 26.F;
constexpr auto default_cqc_fov      = 32.F;

/**
 * hook_update_fov_lerp - Change the target FOV
 * @thisptr:	Struct containing FOV data
 *
 * Check the unmodified focal length and change to the appropriate new one
 */
void __fastcall hook_update_fov_lerp(const uintptr_t thisptr)
{
	auto *target_fov = (float*)(thisptr + 0x2EC);

	*target_fov =
		*target_fov == default_tpp_fov      ? new_tpp_fov :
		*target_fov == default_shoulder_fov ? new_shoulder_fov :
		*target_fov == default_hiding_fov   ? new_hiding_fov :
		*target_fov == default_cqc_fov	    ? new_cqc_fov :
		*target_fov;
}

/**
 * hook_decrypt - Patch the call to the function that updates FOV transitions
 * once the module is unpacked (Fuck Konami)
 *
 * Scan for the signature of the function call, save the original address and
 * patch the offset to a call to our hook
 */
void hook_decrypt()
{
	const auto update_fov_lerp_ref = (int32_t*)(sigscan(
		"mgsvtpp.exe",
		"\x48\x8B\x8F\xF0\x0E\x00\x00\x48\x8B\x01\xFF\x50\x18\x48\x8D\x4F\xE0\xE8",
		"xxxxxxxxxxxxxxxxxx") + 18);

	// Store hook address in RAX because x64 has no 64 bit address CALL instruction
	constexpr auto patch_size = 12;
	const auto update_fov_lerp = (intptr_t)(update_fov_lerp_ref) + *update_fov_lerp_ref + 4;
	const auto hook_call = update_fov_lerp - patch_size;

	DWORD old_protect;
	VirtualProtect((void*)(hook_call), patch_size, PAGE_EXECUTE_READWRITE, &old_protect);
	*(uint16_t*)(hook_call) = 0xB848; // mov rax, hook_update_fov_lerp
	*(void**)(hook_call + 2) = hook_update_fov_lerp;
	*(uint16_t*)(hook_call + 10) = 0xD0FF; // call rax
	VirtualProtect((void*)(hook_call), patch_size, old_protect, &old_protect);

	// Move the CALL destination back to our hook call
	VirtualProtect((void*)(update_fov_lerp_ref), 4, PAGE_EXECUTE_READWRITE, &old_protect);
	*update_fov_lerp_ref -= patch_size;
	VirtualProtect((void*)(update_fov_lerp_ref), 4, old_protect, &old_protect);
}

__declspec(naked) void hook_decrypt_wrap()
{
	_asm call hook_decrypt

	// Do the instructions at the end of the original function
	_asm mov eax, 1
	_asm add rsp, 0x48
	_asm retn
}

/**
 * DllMain - Entry point
 *
 * Calculate camera lens focal lengths from the setting and hook code decryption
 */
BOOL WINAPI DllMain(
	_In_ HINSTANCE hinstDLL,
	_In_ DWORD     fdwReason,
	_In_ LPVOID    lpvReserved
	)
{
	if (fdwReason != DLL_PROCESS_ATTACH)
		return FALSE;

	std::ifstream config("fov.cfg");
	float tpp_fov;
	config >> tpp_fov;

	constexpr auto deg2rad     = 3.1415926F / 180.F;
	constexpr auto frame_width = 36.F;
	const auto tpp_fov_tan     = tan(tpp_fov * deg2rad / 2.F);
	new_tpp_fov      = frame_width / tpp_fov_tan / 2.F;
	new_shoulder_fov = frame_width / (tpp_fov_tan * (default_tpp_fov / default_shoulder_fov)) / 2.F;
	new_hiding_fov   = frame_width / (tpp_fov_tan * (default_tpp_fov / default_hiding_fov)) / 2.F;
	new_cqc_fov      = frame_width / (tpp_fov_tan * (default_tpp_fov / default_cqc_fov)) / 2.F;
	
	const auto decrypt_code_end_jnb = (int32_t*)(sigscan(
		"mgsvtpp.exe",
		"\xD1\xE2\x0F\xAF\xCA\x31\xC8\x8B\x4C\x24\x1C",
		"xxxxxxxxxxx") - 0x279);

	// Write hook code into int3 padding
	const auto int3 = sigscan(
		"mgsvtpp.exe",
		"\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC",
		"xxxxxxxxxxxx");

	// Store hook address in RAX because x64 has no 64 bit address CALL instruction
	constexpr auto patch_size = 12;
	DWORD old_protect;
	VirtualProtect((void*)(int3), patch_size, PAGE_EXECUTE_READWRITE, &old_protect);
	*(uint16_t*)(int3) = 0xB848; // mov rax, hook_decrypt
	*(void**)(int3 + 2) = hook_decrypt_wrap;
	*(uint16_t*)(int3 + 10) = 0xE0FF; // jmp rax
	VirtualProtect((void*)(int3), patch_size, old_protect, &old_protect);

	// Replace the jnb to the end of the decryption code with a jnb to our hook
	VirtualProtect(decrypt_code_end_jnb, 4, PAGE_EXECUTE_READWRITE, &old_protect);
	*decrypt_code_end_jnb = (int32_t)((intptr_t)(int3) - (intptr_t)(decrypt_code_end_jnb + 1));
	VirtualProtect(decrypt_code_end_jnb, 4, old_protect, &old_protect);

	return TRUE;
}