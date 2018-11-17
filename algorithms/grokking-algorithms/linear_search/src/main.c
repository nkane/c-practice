#include <stdio.h>
#include <stdlib.h>
#include <lib/algorithms.c>

#define SIZE 100000000
#define FIND  99999999

int
main()
{
	int *x = (int *)malloc(sizeof(int) * SIZE);
	Generate_Array_Data_Int(x, len(x));
	Linear_Search_Int(x, SIZE, FIND);
	free(x);
	return 0;
}
