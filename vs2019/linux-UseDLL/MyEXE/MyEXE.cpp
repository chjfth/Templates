#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include <MyAPI.h>

/* === Debugging Linux exe with .so from Visual Studio, How To ===

If you just load up this .vcxproj into VSIDE, F7 build(assume success), set a breakpoint
at start of main(), and then F5 start debugging, the debugger definitely fails because
this MyEXE.out does NOT know where to load the libMyAPI.so .

This issue can be settled by setting a project-wide debugger option.

Open this EXE's project-setting dialog, go to [Debugging] -> [Pre-Launch Command],
fill in:

	export LD_LIBRARY_PATH=$(vslinux_RemoteOutAbsDir)

Launch F5 again, now the debugger should work and we see the debugger yellow arrow stop
at the first line of main().

The MSBuild variable vslinux_RemoteOutAbsDir is defined in this EXE's .vcxproj and it
dynamically expands to where the .so and the .out resides. For each BuildConf|Platform
combination you want to debug on, you should set that Pre-Launch Command once again.
Tip: [Pre-Launch Command] settings are saved in the .vcxproj.user file by VSIDE.

*/

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "");
	
	MyAPI_version_st vst = {};
	MyAPI_getversion(&vst);

	printf("EXE: Using MyAPI version: %d.%d.%d.%d\n", vst.major, vst.minor, vst.patch, vst.extra);

	return 0;
}

