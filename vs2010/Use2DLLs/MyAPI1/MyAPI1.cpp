//#define WIN32_LEAN_AND_MEAN
//#include <windows.h>
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

#include "iversion.h"
#include "MyAPI1.h"

DLLEXPORT_MyAPI1
bool DLL_CALLCONV MyAPI1_getversion(struct MyAPI1_version_st *pver)
{
	if(!pver)
		return false;

	pver->major = MyAPI1_vmajor;
	pver->minor = MyAPI1_vminor;
	pver->patch = MyAPI1_vpatch;
	pver->extra = MyAPI1_vextra;

	return true;
}

DLLEXPORT_MyAPI1
void DLL_CALLCONV MyAPI1_printversion()
{
	MyAPI1_version_st vst = {};
	MyAPI1_getversion(&vst);
	printf("MyAPI1 version: %d.%d.%d.%d\n", vst.major, vst.minor, vst.patch, vst.extra);
}
