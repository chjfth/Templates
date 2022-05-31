#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <locale.h>

#include <MyAPI.h>

int _tmain(int argc, TCHAR* argv[])
{
	setlocale(LC_ALL, "");
	
	MyAPI_version_st vst = {};
	MyAPI_getversion(&vst);

	_tprintf(_T("EXE: Using MyAPI(lib) version: %d.%d.%d.%d\n"), vst.major, vst.minor, vst.build, vst.extra);

	return 0;
}

