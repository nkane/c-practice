/*
 * NOTE(nick): failed tonight - trying giving a review tomorrow
 * and attempt again!
 *
 * Write a C function that can be used to sort the elements of
 * a 10-by-20 two-dimensional array of integers.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define global_variable static

global_variable const int Rows = 2;
global_variable const int Columns = 5;

void
GenerateNumbers(int Array[Rows][Columns]);

void
Print2DArray(int Array[Rows][Columns]);

void
Sort(int Array[Rows][Columns]);

int
main()
{
	int TestCase[Rows][Columns] = { 0 };

	GenerateNumbers(TestCase);
	Print2DArray(TestCase);
	Sort(TestCase);
	Print2DArray(TestCase);

	return 0;
}

void
GenerateNumbers(int Array[Rows][Columns])
{
	srand(time(NULL));
	for (int r = 0; r < Rows; ++r)
	{
		for (int c = 0; c < Columns; ++c)
		{
			Array[r][c] = (1 + (rand() % 100));
		}
	}
}

void
Print2DArray(int Array[Rows][Columns])
{
	printf("{\n");
	for (int r = 0; r < Rows; ++r)
	{
		printf("\t{ ");
		for (int c = 0; c < Columns; ++c)
		{
			printf("%3d, ", Array[r][c]);
		}
		printf("},\n");
	}
	printf("\n}\n");
}

void
Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/*
 * NOTE(nick): failed tonight - trying giving a review tomorrow
 * and attempt again!
 *
 * rows: 2
 * columns: 5
 *
 * abstract:
 * {0}: [0][1][2][3][4]
 * {1}: [0][1][2][3][4]
 *
 * reality:
 * {0}: [0][1][2][3][4][5][6][7][8][9]
 *
 */
void
Sort(int Array[Rows][Columns])
{
	for (int i = 0; i < (Rows * Columns); ++i)
	{
		int test = *(*(Array) + i);
		printf("%d", test);
	}
}

