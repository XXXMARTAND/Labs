#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>

#define MAX_SOURCE_SIZE 0x100000

int main (void) {

	int i;

	int LIST_SIZE;

	printf("Enter size");
	scanf("%d", &LIST_SIZE);

	int *A = (int *)malloc(sizeof(int) * LIST_SIZE);
	printf("Enter no \n");
	for (i = 0; i < LIST_SIZE; ++i) {
		scanf("%d", &A[i]);
	}

	FILE *kernel_code_file = fopen("q2.cl", "r");
	if (kernel_code_file == NULL) {
		printf("Kernel loading failed.");
		exit(1);
	}

	char *source_str = (char *)malloc(MAX_SOURCE_SIZE);
	size_t source_size = fread(source_str, 1, MAX_SOURCE_SIZE, kernel_code_file);

	fclose(kernel_code_file);

	cl_platform_id platform_id = NULL;
	cl_device_id device_id = NULL;

	cl_uint ret_num_devices, ret_num_platforms;

	cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_CPU, 1, &device_id, &ret_num_devices);

	cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

	cl_command_queue command_queue = clCreateCommandQueueWithProperties(context, device_id, NULL, &ret);

	cl_mem mem_obj_a = clCreateBuffer(context, CL_MEM_READ_ONLY, LIST_SIZE * sizeof(int), NULL, &ret);

	cl_mem mem_obj_b = clCreateBuffer(context, CL_MEM_WRITE_ONLY, LIST_SIZE * sizeof(int), NULL, &ret);

	ret = clEnqueueWriteBuffer(command_queue, mem_obj_a, CL_TRUE, 0, LIST_SIZE * sizeof(int), A, 0, NULL, NULL);

	cl_program program = clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &ret);

	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

	cl_kernel kernel = clCreateKernel(program, "selection_sort", &ret);

	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&mem_obj_a);
	ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&mem_obj_b);

	size_t global_item_size = LIST_SIZE;
	size_t local_item_size = 1;

	ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);

	ret = clFinish(command_queue);

	int *B = (int *)malloc(sizeof(int) * LIST_SIZE);

	ret = clEnqueueReadBuffer(command_queue, mem_obj_b, CL_TRUE, 0, LIST_SIZE * sizeof(int), B, 0, NULL, NULL);
	printf("Sorted array ");
	for (i = 0; i < LIST_SIZE; ++i) {
		printf(" %d ",B[i]);
	}
	printf("\n");

	clFlush(command_queue);
	clReleaseKernel(kernel);
	clReleaseProgram(program);

	clReleaseMemObject(mem_obj_a);
	clReleaseMemObject(mem_obj_b);
	
	clReleaseCommandQueue(command_queue);
	clReleaseContext(context);

	free(A);
	free(B);
	
	return 0;

}








// __kernel void sel_sort(__global int *A,__global int*B)
// {
// 	int id=get_global_id(0);
// 	int pos=0;
// 	int i;
// 	int n=get_global_size(0);
// 	for(i=0;i<n;i++)
// 		if(A[i]<A[id]||A[i]==A[id]&&i<id)
// 		pos++;
// 		B[pos]=A[id];

// }