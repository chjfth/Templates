#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

#include "iversion.h"
#include "MyAPI.h"

DLLEXPORT_MyAPI
bool MyAPI_getversion(struct MyAPI_version_st *pver)
{
	if(!pver)
		return false;

	pver->major = MyAPI_vmajor;
	pver->minor = MyAPI_vminor;
	pver->build = MyAPI_vbuild;
	pver->extra = MyAPI_vextra;

	return true;
}

DLLEXPORT_MyAPI
void MyAPI_printversion()
{
	MyAPI_version_st vst = {};
	MyAPI_getversion(&vst);
	printf("MyAPI version: %d.%d.%d.%d\n", vst.major, vst.minor, vst.build, vst.extra);
}
