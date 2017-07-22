/*
 * Write a program that initially accepts a set of numerical grades
 * from the keyboard into an array. The maximum number of grades is
 * 50 and data entry should be terminated when a negative number
 * has been entered. Have your program sort and print the grades
 * in descending order.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 50;

void
Swap(int *x, int *y);

void
BubbleSort(int array[], int size);

void
PrintArray(int array[], int size);

int
main()
{
	int Grades[Size] = { 0 };
	int i = 0;
	int temp = 0;

	while (i < len(Grades))
	{
		printf("Enter in a grade [%d]: ", i);
		scanf("%d", &temp);

		if (temp > 0)
		{
			Grades[i] = temp;
			++i;
		}
		else if (temp < 0)
		{
			break;
		}
	}

	PrintArray(Grades, i);
	BubbleSort(Grades, i);
	PrintArray(Grades, i);

	return 0;
}

void
Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void
BubbleSort(int array[], int size)
{
	bool swapped = false;
	for (int i = 0; i < size - 1; ++i)
	{
		swapped = false;
		for (int j = 0; j < size - (1 + i); ++j)
		{
			if (array[j] < array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
				swapped = true;
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}

void
PrintArray(int array[], int size)
{
	printf("Grades: { ");
	for (int i = 0; i < size; ++i)
	{
		printf("%d, ", array[i]);
	}
	printf("}\n");
}

