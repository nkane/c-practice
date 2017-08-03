/*
 * Write a C function that adds respective values of two double
 * dimensional arrays named first and second. Both arrays have
 * 2 rows and 3 columns. For example, element [1][2] of the result
 * array should be the sum of first[1][2] and second[1][2]. Assume
 * the arrays are arrays of integers. The first and second arrays
 * should be initialized as follows:
 *
 * 	First		Second
 * 	16 18 23	24 52 77
 * 	54 91 11	16 19 59
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Rows = 2;
global_variable const int Columns = 3;

void
PrintSumBetween2DArrays(int array1[Rows][Columns], int array2[Rows][Columns]);

int
main()
{
	int First[Rows][Columns] =
	{
		{ 16, 18, 23, },
		{ 54, 91, 11, },
	};
	
	int Second[Rows][Columns] =
	{
		{ 24, 52, 77, },
		{ 16, 19, 59, },
	};

	PrintSumBetween2DArrays(First, Second);

	return 0;
}

void
PrintSumBetween2DArrays(int array1[Rows][Columns], int array2[Rows][Columns])
{
	for (int i = 0; i < Rows; ++i)
	{
		for (int j = 0; j < Columns; ++j)
		{
			printf("Array1[%d]: %d + Array2[%d]: %d = %d\n", i, array1[i][j], j, array2[i][j], (array1[i][j] + array2[i][j]));
		}
	}
}

