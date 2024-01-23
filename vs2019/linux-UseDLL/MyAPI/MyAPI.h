#ifndef __MyAPI_h_
#define __MyAPI_h_

#ifdef __cplusplus
extern"C" {
#endif


// Suggestion/Best-practice using gcc to build a dynamic library(.so):
// The project file should pass to gcc:
//
//		-fvisibility=hidden  -DDLLEXPORT_MyAPI=__attribute__((visibility("default")))
//
// so that functions in your library are defaultly hidden(not exported) but only those 
// decorated with DLLEXPORT_MyAPI are exported. 
//
// I also suggest that `-Bsymbolic` is passed to the linker, so that:
// If this libMyAPI.so defines fooA() and fooB() and fooA() has a statement that calls fooB(),
// fooB() is definitely resolved within this libMyAPI.so, that is, no chance fooA() will call 
// into a fooB() defined in another libBar.so .


#ifndef DLLEXPORT_MyAPI
#define DLLEXPORT_MyAPI
#endif

#ifndef DLL_CALLCONV 
// DLL function calling convention, expand to empty by default
#define DLL_CALLCONV
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
