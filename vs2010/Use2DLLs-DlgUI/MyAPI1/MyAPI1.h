#ifndef __MyAPI1_h_
#define __MyAPI1_h_

#ifdef __cplusplus
extern"C" {
#endif


// Note for compiling for Windows using Visual C++:
// The project file should pass to cl.exe 
//
//		/D DLLEXPORT_MyAPI1=__declspec(dllexport)
//
// so to have the interface functions "exported", even in the case
// that MyAPI1.def file is not passed to linker.

#ifndef DLLEXPORT_MyAPI1
#define DLLEXPORT_MyAPI1
#endif

#ifndef DLL_CALLCONV // DLL function calling convention
#ifdef _WIN32 // target Win32/Win64 OS
#define DLL_CALLCONV __stdcall
#else
#define DLL_CALLCONV
#endif
#endif
	
struct MyAPI1_version_st 
{
	int major, minor, patch, extra;
};

DLLEXPORT_MyAPI1
bool DLL_CALLCONV MyAPI1_getversion(struct MyAPI1_version_st *pver);

DLLEXPORT_MyAPI1
void DLL_CALLCONV MyAPI1_printversion();



#ifdef __cplusplus
} // extern"C" {
#endif

#endif
