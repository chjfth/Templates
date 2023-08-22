//#define WIN32_LEAN_AND_MEAN
//#include <windows.h>
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

#include "iversion.h"
#include "MyAPI2.h"

DLLEXPORT_MyAPI2
bool DLL_CALLCONV MyAPI2_getversion(struct MyAPI2_version_st *pver)
{
	if(!pver)
		return false;

	pver->major = MyAPI2_vmajor;
	pver->minor = MyAPI2_vminor;
	pver->patch = MyAPI2_vpatch;
	pver->extra = MyAPI2_vextra;

	return true;
}

DLLEXPORT_MyAPI2
void DLL_CALLCONV MyAPI2_printversion()
{
	MyAPI2_version_st vst = {};
	MyAPI2_getversion(&vst);
	printf("MyAPI2 version: %d.%d.%d.%d\n", vst.major, vst.minor, vst.patch, vst.extra);
}
