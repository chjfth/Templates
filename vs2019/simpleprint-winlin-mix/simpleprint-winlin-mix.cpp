#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("sizeof(void*) = %d\n", (int)sizeof(void*));
	printf("sizeof(long)  = %d\n", (int)sizeof(long));
	printf("argc = %d\n", argc);
	printf("argv[0] = %s\n", argv[0]);
	
	return argc-1;
}
