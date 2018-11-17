/*
 * 	algorithms.c
 * 	Created By: Nick Kane
 *
 */

#include <stdio.h>
#include <time.h>

#define len(a)(sizeof(a)/sizeof(a[0]))
#define global_variable

#define time_delta(t1, t2)((double)(t1 - t2)/CLOCKS_PER_SEC)

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

int
Linear_Search_Int(int *buffer, int size, int search)
{
	Start_Time = clock();
	int i;
	int found = 0;
	for (i = 0; i < size; i++)
	{
		if (*(buffer + i) == search)
		{
			found = 1;
			break;
		}
	}
	End_Time = clock();
	Spent_Time = time_delta(End_Time,Start_Time);
	printf("Time: %f\n", Spent_Time);
	return found;
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
