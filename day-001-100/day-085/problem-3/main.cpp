/*
 * Using the rand() C library function, fill an array of 1000
 * double-percision numbers with random numbers that have been
 * scaled to the range 1 to 100. Then determine and display
 * the number of random numbers having values between 1 and 50
 * and the numbers greater than 50. 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 1000;

void
GenerateNumbers(int array[], int size);

void
PrintArray(int array[], int size);

int 
CountThreshold(int array[], int size, int min, int max);

int
main()
{
	int TestCase[Size] = { 0 };
	int lowCount = 0;
	int highCount = 0;

	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase));

	lowCount = CountThreshold(TestCase, len(TestCase), 0, 51);
	highCount = CountThreshold(TestCase, len(TestCase), 50, 10000000);
	printf("\nValues between 1 - 50: %d\n", lowCount);
	printf("Values above 50:       %d\n", highCount);
	
	return 0;
}

void
GenerateNumbers(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = (1 + (rand() % 100));
	}
}

void
PrintArray(int array[], int size)
{
	printf("Array: { ");
	for (int i = 0; i < size; ++i)
	{
		printf("%d, ", array[i]);
	}
	printf("}\n");
}

int 
CountThreshold(int array[], int size, int min, int max)
{
	int result = 0;
	for (int i = 0; i < size; ++i)
	{
		if (array[i] < max && array[i] > min)
		{
			++result;
		}
	}
	return result;
}
