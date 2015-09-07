#include <Windows.h>

static class functions {
public:
	FARPROC D3DKMTCloseAdapter;
	FARPROC D3DKMTDestroyAllocation;
	FARPROC D3DKMTDestroyContext;
	FARPROC D3DKMTDestroyDevice;
	FARPROC D3DKMTDestroySynchronizationObject;
	FARPROC D3DKMTQueryAdapterInfo;
	FARPROC D3DKMTSetDisplayPrivateDriverFormat;
	FARPROC D3DKMTSignalSynchronizationObject;
	FARPROC D3DKMTUnlock;
	FARPROC D3DKMTWaitForSynchronizationObject;
	FARPROC EnableFeatureLevelUpgrade;
	FARPROC OpenAdapter10;
	FARPROC OpenAdapter10_2;
	FARPROC D3D11CoreCreateDevice;
	FARPROC D3D11CoreCreateLayeredDevice;
	FARPROC D3D11CoreGetLayeredDeviceSize;
	FARPROC D3D11CoreRegisterLayers;
	FARPROC D3D11CreateDevice;
	FARPROC D3D11CreateDeviceAndSwapChain;
	FARPROC D3DKMTCreateAllocation;
	FARPROC D3DKMTCreateContext;
	FARPROC D3DKMTCreateDevice;
	FARPROC D3DKMTCreateSynchronizationObject;
	FARPROC D3DKMTEscape;
	FARPROC D3DKMTGetContextSchedulingPriority;
	FARPROC D3DKMTGetDeviceState;
	FARPROC D3DKMTGetDisplayModeList;
	FARPROC D3DKMTGetMultisampleMethodList;
	FARPROC D3DKMTGetRuntimeData;
	FARPROC D3DKMTGetSharedPrimaryHandle;
	FARPROC D3DKMTLock;
	FARPROC D3DKMTOpenAdapterFromHdc;
	FARPROC D3DKMTOpenResource;
	FARPROC D3DKMTPresent;
	FARPROC D3DKMTQueryAllocationResidency;
	FARPROC D3DKMTQueryResourceInfo;
	FARPROC D3DKMTRender;
	FARPROC D3DKMTSetAllocationPriority;
	FARPROC D3DKMTSetContextSchedulingPriority;
	FARPROC D3DKMTSetDisplayMode;
	FARPROC D3DKMTSetGammaRamp;
	FARPROC D3DKMTSetVidPnSourceOwner;
	FARPROC D3DKMTWaitForVerticalBlankEvent;
	FARPROC D3DPerformance_BeginEvent;
	FARPROC D3DPerformance_EndEvent;
	FARPROC D3DPerformance_GetStatus;
	FARPROC D3DPerformance_SetMarker;

	functions()
	{
		char path[MAX_PATH];
		GetWindowsDirectory(path, MAX_PATH);
		strcat_s(path, "\\system32\\d3d11.dll");
		const auto module = LoadLibrary(path);
		D3DKMTCloseAdapter = GetProcAddress(module, "D3DKMTCloseAdapter");
		D3DKMTDestroyAllocation = GetProcAddress(module, "D3DKMTDestroyAllocation");
		D3DKMTDestroyContext = GetProcAddress(module, "D3DKMTDestroyContext");
		D3DKMTDestroyDevice = GetProcAddress(module, "D3DKMTDestroyDevice");
		D3DKMTDestroySynchronizationObject = GetProcAddress(module, "D3DKMTDestroySynchronizationObject");
		D3DKMTQueryAdapterInfo = GetProcAddress(module, "D3DKMTQueryAdapterInfo");
		D3DKMTSetDisplayPrivateDriverFormat = GetProcAddress(module, "D3DKMTSetDisplayPrivateDriverFormat");
		D3DKMTSignalSynchronizationObject = GetProcAddress(module, "D3DKMTSignalSynchronizationObject");
		D3DKMTUnlock = GetProcAddress(module, "D3DKMTUnlock");
		D3DKMTWaitForSynchronizationObject = GetProcAddress(module, "D3DKMTWaitForSynchronizationObject");
		EnableFeatureLevelUpgrade = GetProcAddress(module, "EnableFeatureLevelUpgrade");
		OpenAdapter10 = GetProcAddress(module, "OpenAdapter10");
		OpenAdapter10_2 = GetProcAddress(module, "OpenAdapter10_2");
		D3D11CoreCreateDevice = GetProcAddress(module, "D3D11CoreCreateDevice");
		D3D11CoreCreateLayeredDevice = GetProcAddress(module, "D3D11CoreCreateLayeredDevice");
		D3D11CoreGetLayeredDeviceSize = GetProcAddress(module, "D3D11CoreGetLayeredDeviceSize");
		D3D11CoreRegisterLayers = GetProcAddress(module, "D3D11CoreRegisterLayers");
		D3D11CreateDevice = GetProcAddress(module, "D3D11CreateDevice");
		D3D11CreateDeviceAndSwapChain = GetProcAddress(module, "D3D11CreateDeviceAndSwapChain");
		D3DKMTCreateAllocation = GetProcAddress(module, "D3DKMTCreateAllocation");
		D3DKMTCreateContext = GetProcAddress(module, "D3DKMTCreateContext");
		D3DKMTCreateDevice = GetProcAddress(module, "D3DKMTCreateDevice");
		D3DKMTCreateSynchronizationObject = GetProcAddress(module, "D3DKMTCreateSynchronizationObject");
		D3DKMTEscape = GetProcAddress(module, "D3DKMTEscape");
		D3DKMTGetContextSchedulingPriority = GetProcAddress(module, "D3DKMTGetContextSchedulingPriority");
		D3DKMTGetDeviceState = GetProcAddress(module, "D3DKMTGetDeviceState");
		D3DKMTGetDisplayModeList = GetProcAddress(module, "D3DKMTGetDisplayModeList");
		D3DKMTGetMultisampleMethodList = GetProcAddress(module, "D3DKMTGetMultisampleMethodList");
		D3DKMTGetRuntimeData = GetProcAddress(module, "D3DKMTGetRuntimeData");
		D3DKMTGetSharedPrimaryHandle = GetProcAddress(module, "D3DKMTGetSharedPrimaryHandle");
		D3DKMTLock = GetProcAddress(module, "D3DKMTLock");
		D3DKMTOpenAdapterFromHdc = GetProcAddress(module, "D3DKMTOpenAdapterFromHdc");
		D3DKMTOpenResource = GetProcAddress(module, "D3DKMTOpenResource");
		D3DKMTPresent = GetProcAddress(module, "D3DKMTPresent");
		D3DKMTQueryAllocationResidency = GetProcAddress(module, "D3DKMTQueryAllocationResidency");
		D3DKMTQueryResourceInfo = GetProcAddress(module, "D3DKMTQueryResourceInfo");
		D3DKMTRender = GetProcAddress(module, "D3DKMTRender");
		D3DKMTSetAllocationPriority = GetProcAddress(module, "D3DKMTSetAllocationPriority");
		D3DKMTSetContextSchedulingPriority = GetProcAddress(module, "D3DKMTSetContextSchedulingPriority");
		D3DKMTSetDisplayMode = GetProcAddress(module, "D3DKMTSetDisplayMode");
		D3DKMTSetGammaRamp = GetProcAddress(module, "D3DKMTSetGammaRamp");
		D3DKMTSetVidPnSourceOwner = GetProcAddress(module, "D3DKMTSetVidPnSourceOwner");
		D3DKMTWaitForVerticalBlankEvent = GetProcAddress(module, "D3DKMTWaitForVerticalBlankEvent");
		D3DPerformance_BeginEvent = GetProcAddress(module, "D3DPerformance_BeginEvent");
		D3DPerformance_EndEvent = GetProcAddress(module, "D3DPerformance_EndEvent");
		D3DPerformance_GetStatus = GetProcAddress(module, "D3DPerformance_GetStatus");
		D3DPerformance_SetMarker = GetProcAddress(module, "D3DPerformance_SetMarker");
	}
} functions;
void D3DKMTCloseAdapter() { functions.D3DKMTCloseAdapter(); }
void D3DKMTDestroyAllocation() { functions.D3DKMTDestroyAllocation(); }
void D3DKMTDestroyContext() { functions.D3DKMTDestroyContext(); }
void D3DKMTDestroyDevice() { functions.D3DKMTDestroyDevice(); }
void D3DKMTDestroySynchronizationObject() { functions.D3DKMTDestroySynchronizationObject(); }
void D3DKMTQueryAdapterInfo() { functions.D3DKMTQueryAdapterInfo(); }
void D3DKMTSetDisplayPrivateDriverFormat() { functions.D3DKMTSetDisplayPrivateDriverFormat(); }
void D3DKMTSignalSynchronizationObject() { functions.D3DKMTSignalSynchronizationObject(); }
void D3DKMTUnlock() { functions.D3DKMTUnlock(); }
void D3DKMTWaitForSynchronizationObject() { functions.D3DKMTWaitForSynchronizationObject(); }
void EnableFeatureLevelUpgrade() { functions.EnableFeatureLevelUpgrade(); }
void OpenAdapter10() { functions.OpenAdapter10(); }
void OpenAdapter10_2() { functions.OpenAdapter10_2(); }
void D3D11CoreCreateDevice() { functions.D3D11CoreCreateDevice(); }
void D3D11CoreCreateLayeredDevice() { functions.D3D11CoreCreateLayeredDevice(); }
void D3D11CoreGetLayeredDeviceSize() { functions.D3D11CoreGetLayeredDeviceSize(); }
void D3D11CoreRegisterLayers() { functions.D3D11CoreRegisterLayers(); }
void D3D11CreateDevice() { functions.D3D11CreateDevice(); }
void D3D11CreateDeviceAndSwapChain() { functions.D3D11CreateDeviceAndSwapChain(); }
void D3DKMTCreateAllocation() { functions.D3DKMTCreateAllocation(); }
void D3DKMTCreateContext() { functions.D3DKMTCreateContext(); }
void D3DKMTCreateDevice() { functions.D3DKMTCreateDevice(); }
void D3DKMTCreateSynchronizationObject() { functions.D3DKMTCreateSynchronizationObject(); }
void D3DKMTEscape() { functions.D3DKMTEscape(); }
void D3DKMTGetContextSchedulingPriority() { functions.D3DKMTGetContextSchedulingPriority(); }
void D3DKMTGetDeviceState() { functions.D3DKMTGetDeviceState(); }
void D3DKMTGetDisplayModeList() { functions.D3DKMTGetDisplayModeList(); }
void D3DKMTGetMultisampleMethodList() { functions.D3DKMTGetMultisampleMethodList(); }
void D3DKMTGetRuntimeData() { functions.D3DKMTGetRuntimeData(); }
void D3DKMTGetSharedPrimaryHandle() { functions.D3DKMTGetSharedPrimaryHandle(); }
void D3DKMTLock() { functions.D3DKMTLock(); }
void D3DKMTOpenAdapterFromHdc() { functions.D3DKMTOpenAdapterFromHdc(); }
void D3DKMTOpenResource() { functions.D3DKMTOpenResource(); }
void D3DKMTPresent() { functions.D3DKMTPresent(); }
void D3DKMTQueryAllocationResidency() { functions.D3DKMTQueryAllocationResidency(); }
void D3DKMTQueryResourceInfo() { functions.D3DKMTQueryResourceInfo(); }
void D3DKMTRender() { functions.D3DKMTRender(); }
void D3DKMTSetAllocationPriority() { functions.D3DKMTSetAllocationPriority(); }
void D3DKMTSetContextSchedulingPriority() { functions.D3DKMTSetContextSchedulingPriority(); }
void D3DKMTSetDisplayMode() { functions.D3DKMTSetDisplayMode(); }
void D3DKMTSetGammaRamp() { functions.D3DKMTSetGammaRamp(); }
void D3DKMTSetVidPnSourceOwner() { functions.D3DKMTSetVidPnSourceOwner(); }
void D3DKMTWaitForVerticalBlankEvent() { functions.D3DKMTWaitForVerticalBlankEvent(); }
void D3DPerformance_BeginEvent() { functions.D3DPerformance_BeginEvent(); }
void D3DPerformance_EndEvent() { functions.D3DPerformance_EndEvent(); }
void D3DPerformance_GetStatus() { functions.D3DPerformance_GetStatus(); }
void D3DPerformance_SetMarker() { functions.D3DPerformance_SetMarker(); }
