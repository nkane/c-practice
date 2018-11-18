#include <stdlib.h> 
#include <lib/algorithms.c>
#include <assert.h>

#define SIZE 100
#define FIND  99

int
main()
{
	int *x = (int *)malloc(sizeof(int) * SIZE);
	Generate_Array_Data_Int(x, SIZE);
	Print_Array_Data(x, SIZE, 'd');
	int found = Binary_Search_Int(x, SIZE, FIND);
	assert(found == 1);
	free(x);
	return 0;
}
