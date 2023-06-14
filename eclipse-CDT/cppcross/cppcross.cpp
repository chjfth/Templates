#include <stdio.h>
#include <stdlib.h>
//#include <tchar.h>
#include <locale.h>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "");
	
	printf("Hello, cppcross!\n");
	printf("argv[0] = %s\n", argv[0]);
	return 0;
}
