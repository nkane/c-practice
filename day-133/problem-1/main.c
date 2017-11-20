/*
 * Modify the findMax() function to locate the minimum value of the passed array.
 * Write the function using only pointers and rename the function findMin().
 *
 */

#include <stdio.h>

int
FindMax(int array[], int size);

int
main()
{
	return 0;
}

int
FindMax(int array[], int size)
{
	int i, max = array[0];
	for (i = 1; i < size; ++i)
	{
		if (max < array[i])
		{
			max = value[i];
		}
	}
	return max;
}
