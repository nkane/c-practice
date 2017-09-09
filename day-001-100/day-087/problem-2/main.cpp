/*
 * Write a function that multiplies each element of a 7-by-10 
 * array of integers by a scalar number. Both the array name
 * and the number by which each element is to be multiplied
 * are to be passed into the function as arguments. Assume
 * the array is an array of integers.
 *
 */

#include <stdio.h>

#define global_variable static

#define row_len(array)(sizeof(array)/sizeof(array[0]))
#define column_len(array)(sizeof(array[0])/sizeof(array[0][0]))

// NOTE(nick): tested with 2 by 3 instead of 7 by 10
global_variable const int X = 2;
global_variable const int Y = 3;

void
ApplyScalar2D(int array[X][Y], int rows, int columns, int scalarValue);

int
main()
{
	// ints are 4 bytes
	// row = 2
	// columns = 3
	// each row is 3 * 4 bytes = 12 bytes
	// 1 row at 12 bytes * 2 rows = 24 bytes
	int TestCase[X][Y] = 
	{
		{ 1, 2, 3, },
		{ 4, 5, 6, },
	};

	ApplyScalar2D(TestCase, row_len(TestCase), column_len(TestCase), 10);

	return 0;
}

void
ApplyScalar2D(int array[X][Y], int rows, int columns, int scalarValue)
{
	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < columns; ++c)
		{
			array[r][c] *= scalarValue;
			printf("Value [%d][%d]: %d\n", r, c, array[r][c]);
		}
	}
}

