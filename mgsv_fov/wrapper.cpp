#include <Windows.h>

static class functions {
public:
	FARPROC CheckETWTLS;
	FARPROC CompatString;
	FARPROC CompatValue;
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
	FARPROC DXGIDumpJournal;
	FARPROC DXGIRevertToSxS;
	FARPROC OpenAdapter10;
	FARPROC OpenAdapter10_2;
	FARPROC SetAppCompatStringPointer;
	FARPROC CreateDXGIFactory1;
	FARPROC CreateDXGIFactory;
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
	FARPROC DXGID3D10CreateDevice;
	FARPROC DXGID3D10CreateLayeredDevice;
	FARPROC DXGID3D10ETWRundown;
	FARPROC DXGID3D10GetLayeredDeviceSize;
	FARPROC DXGID3D10RegisterLayers;
	FARPROC DXGIReportAdapterConfiguration;

	functions()
	{
		char path[MAX_PATH];
		GetWindowsDirectory(path, MAX_PATH);
		strcat_s(path, "\\system32\\dxgi.dll");
		const auto module = LoadLibrary(path);
		CheckETWTLS = GetProcAddress(module, "CheckETWTLS");
		CompatString = GetProcAddress(module, "CompatString");
		CompatValue = GetProcAddress(module, "CompatValue");
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
		DXGIDumpJournal = GetProcAddress(module, "DXGIDumpJournal");
		DXGIRevertToSxS = GetProcAddress(module, "DXGIRevertToSxS");
		OpenAdapter10 = GetProcAddress(module, "OpenAdapter10");
		OpenAdapter10_2 = GetProcAddress(module, "OpenAdapter10_2");
		SetAppCompatStringPointer = GetProcAddress(module, "SetAppCompatStringPointer");
		CreateDXGIFactory1 = GetProcAddress(module, "CreateDXGIFactory1");
		CreateDXGIFactory = GetProcAddress(module, "CreateDXGIFactory");
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
		DXGID3D10CreateDevice = GetProcAddress(module, "DXGID3D10CreateDevice");
		DXGID3D10CreateLayeredDevice = GetProcAddress(module, "DXGID3D10CreateLayeredDevice");
		DXGID3D10ETWRundown = GetProcAddress(module, "DXGID3D10ETWRundown");
		DXGID3D10GetLayeredDeviceSize = GetProcAddress(module, "DXGID3D10GetLayeredDeviceSize");
		DXGID3D10RegisterLayers = GetProcAddress(module, "DXGID3D10RegisterLayers");
		DXGIReportAdapterConfiguration = GetProcAddress(module, "DXGIReportAdapterConfiguration");
	}
} functions;
void CheckETWTLS() { functions.CheckETWTLS(); }
void CompatString() { functions.CompatString(); }
void CompatValue() { functions.CompatValue(); }
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
void DXGIDumpJournal() { functions.DXGIDumpJournal(); }
void DXGIRevertToSxS() { functions.DXGIRevertToSxS(); }
void OpenAdapter10() { functions.OpenAdapter10(); }
void OpenAdapter10_2() { functions.OpenAdapter10_2(); }
void SetAppCompatStringPointer() { functions.SetAppCompatStringPointer(); }
void CreateDXGIFactory1() { functions.CreateDXGIFactory1(); }
void CreateDXGIFactory() { functions.CreateDXGIFactory(); }
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
void DXGID3D10CreateDevice() { functions.DXGID3D10CreateDevice(); }
void DXGID3D10CreateLayeredDevice() { functions.DXGID3D10CreateLayeredDevice(); }
void DXGID3D10ETWRundown() { functions.DXGID3D10ETWRundown(); }
void DXGID3D10GetLayeredDeviceSize() { functions.DXGID3D10GetLayeredDeviceSize(); }
void DXGID3D10RegisterLayers() { functions.DXGID3D10RegisterLayers(); }
void DXGIReportAdapterConfiguration() { functions.DXGIReportAdapterConfiguration(); }
