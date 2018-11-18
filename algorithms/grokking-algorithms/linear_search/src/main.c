#include <stdio.h>
#include <stdlib.h>
#include <lib/algorithms.c>
#include <assert.h>

#define SIZE 128
#define FIND  64

int
main()
{
	int *x = (int *)malloc(sizeof(int) * SIZE);
	Generate_Array_Data_Int(x, SIZE);
	int found = Linear_Search_Int(x, SIZE, FIND);
	assert(found == 1);
	free(x);
	return 0;
}
