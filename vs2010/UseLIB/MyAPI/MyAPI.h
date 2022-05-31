#ifndef __MyAPI_h_
#define __MyAPI_h_

#ifdef __cplusplus
extern"C" {
#endif


struct MyAPI_version_st 
{
	int major, minor, patch, extra;
};


bool MyAPI_getversion(struct MyAPI_version_st *pver);


void MyAPI_printversion();



#ifdef __cplusplus
} // extern"C" {
#endif

#endif
