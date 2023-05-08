#ifndef __MyAPI_h_
#define __MyAPI_h_

#ifdef __cplusplus
extern"C" {
#endif


// Note for compiling for Windows using Visual C++:
// The project file should pass to cl.exe 
//
//		/D DLLEXPORT_MyAPI=__declspec(dllexport)
//
// so to have the interface functions "exported", even in the case
// that MyAPI.def file is not passed to linker.

#ifndef DLLEXPORT_MyAPI
#define DLLEXPORT_MyAPI
#endif

#ifndef DLL_CALLCONV // DLL function calling convention
#ifdef _WIN32 // target Win32/Win64 OS
#define DLL_CALLCONV __stdcall
#else
#define DLL_CALLCONV
#endif
#endif
	
struct MyAPI_version_st 
{
	int major, minor, patch, extra;
};

DLLEXPORT_MyAPI
bool DLL_CALLCONV MyAPI_getversion(struct MyAPI_version_st *pver);

DLLEXPORT_MyAPI
void DLL_CALLCONV MyAPI_printversion();



#ifdef __cplusplus
} // extern"C" {
#endif

#endif
