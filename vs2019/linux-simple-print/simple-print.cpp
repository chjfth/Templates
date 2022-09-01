#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("sizeof(void*) = %d\n", sizeof(void*));
	printf("argc = %d\n", argc);
	printf("argv[0] = %s\n", argv[0]);
	
	return argc-1;
}
