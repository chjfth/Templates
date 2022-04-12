#ifndef __MyAPI_h_
#define __MyAPI_h_

#ifdef __cplusplus
extern"C" {
#endif


#ifndef DLLEXPORT_MyAPI
#define DLLEXPORT_MyAPI
#endif

#ifndef DLL_CALLCONV // DLL function calling convention
#define DLL_CALLCONV __stdcall
#endif
	
struct MyAPI_version_st 
{
	int major, minor, build, extra;
};

DLLEXPORT_MyAPI
bool DLL_CALLCONV MyAPI_getversion(struct MyAPI_version_st *pver);

DLLEXPORT_MyAPI
void DLL_CALLCONV MyAPI_printversion();



#ifdef __cplusplus
} // extern"C" {
#endif

#endif
