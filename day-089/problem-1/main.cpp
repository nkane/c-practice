/*
 * Write a C function that finds and displays the maximum value in a 
 * two-dimensional array of integers. The array should be declared as
 * a 10-row-by-20-column array of integers in main(), and the starting
 * address of the array should be passed to the function:
 * 	
 * Display the row and column number of the element with the maximum value.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define global_variable static

global_variable const int Rows = 10;
global_variable const int Columns = 20;


struct SearchResult
{
	int MaxValue;
	int MaxRow;
	int MaxColumn;
};

void
GenerateNumbers(int TestCase[Rows][Columns]);

SearchResult
FindMaxValue(int TestCase[Rows][Columns]);

int
main()
{
	int TestCase[Rows][Columns] = { 0 };

	GenerateNumbers(TestCase);
	SearchResult Result = FindMaxValue(TestCase);

	printf("Max Value: %d\n", Result.MaxValue);
	printf("Max Row: %d\n", Result.MaxRow);
	printf("Max Column: %d\n", Result.MaxColumn);

	return 0;
}

void
GenerateNumbers(int TestCase[Rows][Columns])
{
	srand(time(NULL));
	for (int r = 0; r < Rows; ++r)
	{
		for (int c = 0; c < Columns; ++c)
		{
			TestCase[r][c] = (1 + (rand() % 1000));
		}
	}
}

SearchResult
FindMaxValue(int TestCase[Rows][Columns])
{
	SearchResult Result = {};
	int r = 0;
	int c = 0;
	Result.MaxRow = r;
	Result.MaxColumn = c;
	Result.MaxValue = TestCase[r][c];
	for (r = 1; r < Rows; ++r)
	{
		for (c = 0; c < Columns; ++c)
		{
			if  (Result.MaxValue < TestCase[r][c])
			{
				Result.MaxRow = r;
				Result.MaxColumn = c;
				Result.MaxValue = TestCase[r][c];
			}
		}
	}
	return Result;
}

