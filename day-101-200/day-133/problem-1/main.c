/*
 * Modify the findMax() function to locate the minimum value of the passed array.
 * Write the function using only pointers and rename the function findMin().
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

int
FindMax(int *array, int size);

int
FindMin(int *array, int size);

void
PrintArray(int *array, int size);

int
main()
{
	int array[] = { 13, 15, 23, 92, 10, 19, 11, 40, };

	PrintArray(array, len(array));
	printf("Max: %d\n", FindMax(array, len(array)));
	printf("Min: %d\n", FindMin(array, len(array)));

	return 0;
}

int
FindMax(int array[], int size)
{
	int i = 0;
	int temp = 0;
	int max = *(array + i);
	for (i = 1; i < size; ++i)
	{
		temp = *(array + i);
		if (max < temp)
		{
			max = temp;
		}
	}
	return max;
}

int
FindMin(int *array, int size)
{
	int i = 0;
	int temp = 0;
	int min = *(array + i);
	for (i = 1; i < size; ++i)
	{
		temp = *(array + i);
		if (min > temp)
		{
			min = temp;
		}
	}
	return min;
}

void
PrintArray(int *array, int size)
{
	int i;
	printf("Array: { ");
	for (i = 0; i < size; ++i)
	{
		printf("%d, ", *(array + i));
	}
	printf("}\n");
}
