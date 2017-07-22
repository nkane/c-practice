/*
 * Write and test a function that returns the position
 * of the largest and smallest values in an array of
 * double percision numbers.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_varaible static

global_varaible const int Size = 5;

struct Data
{
	int Min;
	int Max;
};

Data
FindMinMax(double array[], int size);

int
main()
{
	double TestCase[Size] = { 3, 2, 6, 10, -1 };
	Data D = FindMinMax(TestCase, len(TestCase));

	printf("Min Index: %d - value: %lf\n", D.Min, TestCase[D.Min]);
	printf("Max Index: %d - value: %lf\n", D.Max, TestCase[D.Max]);

	return 0;
}

Data
FindMinMax(double array[], int size)
{
	Data D = { 0, 0 };
	for (int i = 1; i < size; ++i)
	{
		if (array[D.Min] > array[i])
		{
			D.Min = i;
		}

		if (array[i] > array[D.Max])
		{
			D.Max = i;
		}
	}
	return D;
}

