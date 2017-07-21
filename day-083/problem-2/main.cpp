/*
 * Modify Program 8.6 so that a function named sort is
 * called after the call to the stdDev function. The 
 * sort function should sort the grades into increasing
 * order for display by main().
 *
 */

#include <stdio.h>
#include <math.h>

#define global_variable

global_variable const int Size = 10;

double
FindAverage(int array[], int size);

double
StandardDeviation(int array[], int size, int average);

void
InsertionSort(int array[], int size);

void
PrintArray(int array[], int size);

int
main()
{
	int highest = 0;
	int value[Size] = { 98, 82, 67, 54, 78, 83, 95, 76, 68, 63, };
	double average, standardDeviation;

	average = FindAverage(value, Size);
	standardDeviation = StandardDeviation(value, Size, average);
	InsertionSort(value, Size);
	PrintArray(value, Size);

	printf("The average of the numbers is %5.2f\n", average);
	printf("The standard deviation of the numbers is %5.2f\n", standardDeviation);

	return 0;
}

double
FindAverage(int array[], int size)
{
	double sum = 0.0;
	for (int i = 0; i < size; ++i)
	{
		sum += array[i];
	}
	return (sum / size);
}

double
StandardDeviation(int array[], int size, int average)
{
	double sum = 0.0;
	for (int i = 0; i < size; ++i)
	{
		sum += pow((array[i] - average), 2);
	}
	return (sqrt(sum / size));
}

void
InsertionSort(int array[], int size)
{
	int i = 0;
	int j = 0;
	int key = 0;

	for (i = 1; i < size; ++i)
	{
		key = array[i];
		j = i - 1;
		
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
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

