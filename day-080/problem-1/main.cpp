/*
 * Modify the findMax() function in Program 8.5 to locate
 * the minimum value of the passed array. 
 * Rename the function findMin().
 *
 */

#include <stdio.h>


#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 5;

int
findMax(int array[], int size);

int
findMin(int array[], int size);

void
PrintArray(int array[], int size);

int
main()
{
	int x[Size] = { 2, 18, 1, 27, 16, };

	PrintArray(x, len(x));

	int max = findMax(x, len(x));
	int min = findMin(x, len(x)); 

	printf("Max: %d\n", max);
	printf("Min: %d\n", min);

	return 0;
}

int
findMax(int array[], int size)
{
	int max = array[0];

	for (int i = 1; i < size; ++i)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}

int
findMin(int array[], int size)
{
	int min = array[0];
	for (int i = 1; i < size; ++i)
	{
		if (min > array[i])
		{
			min = array[i];
		}
	}
	return min;
}

void
PrintArray(int array[], int size)
{
	printf("Array: { ");
	for (int i = 0; i < size; ++i)
	{
		printf("%d, ", array[i]);
	}
	printf("}\n");
}

