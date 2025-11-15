#ifndef __MyStaticLib_h_
#define __MyStaticLib_h_

#ifdef __cplusplus
extern"C" {
#endif


struct MyStaticLib_version_st 
{
	int major, minor, patch, extra;
};


bool MyStaticLib_getversion(struct MyStaticLib_version_st *pver);


void MyStaticLib_printversion();



#ifdef __cplusplus
} // extern"C" {
#endif

#endif
