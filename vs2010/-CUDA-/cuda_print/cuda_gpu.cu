#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

// Note: nvcc.exe will include necessary CUDA .h headers automatically,
// so we do not have to #include them manually.

extern"C" void test_call_cuda()
{
	int gpu_count = 0;
	cudaError_t err = cudaGetDeviceCount(&gpu_count);
	if(err)
	{
		_tprintf(_T("cudaGetDeviceCount() error = %d\n"), err);
		return;
	}
	else
	{
		_tprintf(_T("gpu_count = %d\n"), gpu_count);
	}
}
