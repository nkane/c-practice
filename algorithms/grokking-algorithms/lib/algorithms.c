/*
 * 	algorithms.c
 * 	Created By: Nick Kane
 *
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define len(a)(sizeof(a)/sizeof(a[0]))
#define global_variable

#define start_clock Start_Time = clock()
#define stop_clock End_Time = clock()
#define time_delta(t1, t2)((double)(t1 - t2)/CLOCKS_PER_SEC)
#define print_time(t)\
	printf("Time: %f seconds\n", t)\

#define clock_print\
	Spent_Time = time_delta(End_Time, Start_Time);\
	print_time(Spent_Time)\

global_variable clock_t Start_Time;
global_variable clock_t End_Time;
global_variable double Spent_Time;

void
Generate_Array_Data_Int(int *buffer, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		*(buffer + i) = i;
	}
}

void
Generate_Array_Random_Data_Int(int *buffer, int size, int min, int max)
{
	int i;
	srand(time(0));
	for (i = 0; i < size; i++)
	{
		*(buffer + i) = (min + rand() % (max + 1 - min));
	}
}

int
Linear_Search_Int(int *buffer, int size, int search)
{
	start_clock;
	int i;
	int found = 0;
	int guess = 0;
	for (i = 0; i < size; i++)
	{
		guess = *(buffer + i);
		if (guess == search)
		{
			found = 1;
			break;
		}
	}
	stop_clock;
	clock_print;
	return found;
}

int
Binary_Search_Int(int *buffer, int size, int search)
{
	start_clock;
	int found = 0;
	int min = 0;
	int max = (size - 1);
	int mid = 0;
	int guess = 0;
	while (min <= max)
	{
		mid = ((min + max) / 2);
		guess = *(buffer + mid);
		if (guess == search)
		{
			found = 1;
			break;
		}
		else if (guess > search)
		{
			max = (mid - 1);
		}
		else
		{
			min = mid + 1;
		}
	}
	stop_clock;
	clock_print;
	return found;
}

void
Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int
Bubble_Sort(int *buffer, int size)
{
	start_clock;
	int swapped = 1;
	int i;
	int j;
	for (i = 0; i < size - 1 && swapped == 1; i++)
	{
		swapped = 0;
		for (j = 0 ; j < size - (i + 1); j++)
		{
			if (*(buffer + j) > *(buffer + (j + 1)))
			{
				Swap((buffer + j), (buffer + (j + 1)));
				swapped = 1;
			}
		}
	}
	stop_clock;
	clock_print;
	return 0;
}

int
Selection_Sort(int *buffer, int size)
{
	start_clock;
	int i = 0;
	int j = 0;
	int min_index;
	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (*(buffer + j) < *(buffer + min_index))
			{
				min_index = j;
			}
		}
		Swap((buffer + min_index), (buffer + i));
	}
	stop_clock;
	clock_print;
	return 0;
}

void
Print_Array_Data(void *buffer, int size, const char formatter)
{
	int i;
	for (i = 0; i < size; i++)
	{
		switch (formatter)
		{
			case 'd':
			{
				printf("%d", (int)(*((int *)buffer + i)));
			} break;

			default:
			{
				// none provided
			} break;
		}
		if ((i + 1) < size)
		{
			printf(",");
		}
		else
		{
			printf("\n");
		}
	}
}
