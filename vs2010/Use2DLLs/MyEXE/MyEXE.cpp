#include <stdio.h>
#include <stdlib.h>
//#include <tchar.h>
#include <locale.h>

#include <MyAPI1.h>
#include <MyAPI2.h>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "");
	
	MyAPI1_version_st vst1 = {};
	MyAPI1_getversion(&vst1);

	printf("EXE: Using MyAPI1 version: %d.%d.%d.%d\n", vst1.major, vst1.minor, vst1.patch, vst1.extra);

	MyAPI2_version_st vst2 = {};
	MyAPI2_getversion(&vst2);

	printf("EXE: Using MyAPI2 version: %d.%d.%d.%d\n", vst2.major, vst2.minor, vst2.patch, vst2.extra);
	
	return 0;
}

