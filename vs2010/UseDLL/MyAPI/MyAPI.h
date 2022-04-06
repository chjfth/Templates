#ifndef __MyAPI_h_
#define __MyAPI_h_

#ifndef DLLEXPORT_MyAPI
#define DLLEXPORT_MyAPI
#endif

struct MyAPI_version_st 
{
	int major, minor, build, extra;
};

DLLEXPORT_MyAPI
MyAPI_getversion(struct MyAPI_getversion *pver);

#endif
