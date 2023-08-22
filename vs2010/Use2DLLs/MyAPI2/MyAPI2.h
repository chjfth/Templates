#ifndef __MyAPI2_h_
#define __MyAPI2_h_

#ifdef __cplusplus
extern"C" {
#endif


// Note for compiling for Windows using Visual C++:
// The project file should pass to cl.exe 
//
//		/D DLLEXPORT_MyAPI2=__declspec(dllexport)
//
// so to have the interface functions "exported", even in the case
// that MyAPI2.def file is not passed to linker.

#ifndef DLLEXPORT_MyAPI2
#define DLLEXPORT_MyAPI2
#endif

#ifndef DLL_CALLCONV // DLL function calling convention
#ifdef _WIN32 // target Win32/Win64 OS
#define DLL_CALLCONV __stdcall
#else
#define DLL_CALLCONV
#endif
#endif
	
struct MyAPI2_version_st 
{
	int major, minor, patch, extra;
};

DLLEXPORT_MyAPI2
bool DLL_CALLCONV MyAPI2_getversion(struct MyAPI2_version_st *pver);

DLLEXPORT_MyAPI2
void DLL_CALLCONV MyAPI2_printversion();



#ifdef __cplusplus
} // extern"C" {
#endif

#endif
