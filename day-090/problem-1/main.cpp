/*
 * Write a C function that can be used to sort the elements of
 * a 10-by-20 two-dimensional array of integers.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define global_variable static

global_variable const int Rows = 10;
global_variable const int Columns = 20;

void
GenerateNumber2D(int array[Rows][Columns]);

void
PrintArray2D(int array[Rows][Columns]);

void
Swap(int *x, int *y);

void
BubbleSort(int array[Rows][Columns]);

int
main()
{
	int TestCase[Rows][Columns] = { 0 };

	GenerateNumber2D(TestCase);
	PrintArray2D(TestCase);

	BubbleSort(TestCase);

	PrintArray2D(TestCase);

	return 0;
}

void
GenerateNumber2D(int array[Rows][Columns])
{
	srand(time(NULL));
	for (int i = 0; i < (Rows * Columns); ++i)
	{
		*((*array) + i) = (1 + (rand() % 100));
	}
}

void
PrintArray2D(int array[Rows][Columns])
{
	printf("{\n");
	for (int r = 0; r < Rows; ++r)
	{
		printf("\t{ ");
		for (int c = 0; c < Columns; ++c)
		{
			printf("%d, ", array[r][c]);
		}
		printf("},\n");
	}
	printf("}\n");
}

void
Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// NOTE(nick): not worried about optimizations for this problem
void
BubbleSort(int array[Rows][Columns])
{
	for (int i = 0; i < (Rows * Columns) - 1; ++i)
	{
		for (int j = 0; j < (Rows * Columns) - (1 + i); ++j)
		{
			if (*((*array) + j) > (*((*array) + (j + 1))))
			{
				Swap(((*array) + j), ((*array) + (j + 1)));
			}
		}
	}
}

