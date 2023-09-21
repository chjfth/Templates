#include <stdio.h>
#include <stdlib.h>

// Note: nvcc.exe will include necessary CUDA .h headers automatically,
// so we do not have to #include them manually. (at least for CUDA 8.0)

extern"C" void 
main_cuda_print(int argc, char* argv[])
{
	int gpu_count = 0;
	cudaError_t err = cudaGetDeviceCount(&gpu_count);
	if(err)
	{
		printf("cudaGetDeviceCount() error = %d\n", err);
		return;
	}
	else
	{
		printf("gpu_count = %d\n", gpu_count);
	}
}
