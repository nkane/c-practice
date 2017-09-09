/*
 * Write a C function that adds the values of all elements in a 
 * two-dimensional array that is passed to the function. Assume
 * that the array is an array of double precision numbers having
 * 4 rows and 5 columns.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Rows = 4;
global_variable const int Columns = 5;

int
Sum2DArray(int array[Rows][Columns]);

int
main()
{
	int TestCase [Rows][Columns]
	{
		{ 1, 2, 4, 8, 16 },
		{ 1, 2, 4, 8, 16 },
		{ 1, 2, 4, 8, 16 },
		{ 1, 2, 4, 8, 16 },
	};

	printf("The Sum is: %d\n", Sum2DArray(TestCase));

	return 0;
}

int
Sum2DArray(int array[Rows][Columns])
{
	int Result = 0;
	for (int i = 0; i < Rows; ++i)
	{
		for (int j = 0; j < Columns; ++j)
		{
			Result += array[i][j];
		}
	}
	return Result;
}

