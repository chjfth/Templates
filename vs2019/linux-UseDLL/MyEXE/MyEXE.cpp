#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include <MyAPI.h>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "");
	
	MyAPI_version_st vst = {};
	MyAPI_getversion(&vst);

	printf("EXE: Using MyAPI version: %d.%d.%d.%d\n", vst.major, vst.minor, vst.patch, vst.extra);

	return 0;
}

