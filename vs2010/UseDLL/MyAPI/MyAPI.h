#ifndef __MyAPI_h_
#define __MyAPI_h_

#ifdef __cplusplus
extern"C" {
#endif


#ifndef DLLEXPORT_MyAPI
#define DLLEXPORT_MyAPI
#endif

struct MyAPI_version_st 
{
	int major, minor, build, extra;
};

DLLEXPORT_MyAPI
bool MyAPI_getversion(struct MyAPI_version_st *pver);

DLLEXPORT_MyAPI
void MyAPI_printversion();



#ifdef __cplusplus
} // extern"C" {
#endif

#endif
