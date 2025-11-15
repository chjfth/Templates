#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

#include "iversion.h"
#include "MyStaticLib.h"


bool MyStaticLib_getversion(struct MyStaticLib_version_st *pver)
{
	if(!pver)
		return false;

	pver->major = MyStaticLib_vmajor;
	pver->minor = MyStaticLib_vminor;
	pver->patch = MyStaticLib_vpatch;
	pver->extra = MyStaticLib_vextra;

	return true;
}


void MyStaticLib_printversion()
{
	MyStaticLib_version_st vst = {};
	MyStaticLib_getversion(&vst);
	printf("MyStaticLib version: %d.%d.%d.%d\n", vst.major, vst.minor, vst.patch, vst.extra);
}
