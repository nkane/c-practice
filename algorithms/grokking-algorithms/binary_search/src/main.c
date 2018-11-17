#include <stdlib.h> 
#include <lib/algorithms.c>

#define SIZE 100
#define FIND  99

int
main()
{
	int *x = (int *)malloc(sizeof(int) * SIZE);
	Generate_Array_Data_Int(x, len(x));
	Binary_Search_Int(x, SIZE, FIND);
	free(x);
	return 0;
}
