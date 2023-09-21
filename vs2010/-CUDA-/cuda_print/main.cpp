#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <locale.h>

extern"C" void main_cuda_print(int argc, char* argv[]);

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "");
	
	printf("Hello, cuda_print!\n");

	main_cuda_print(argc, argv);

	return 0;
}

