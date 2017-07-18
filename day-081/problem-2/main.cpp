/*
 * Write a C program that includes two functions named calcAvg()
 * and variance(). The calcAvg() function should calculate and return
 * the average of the values stored in an array named testvals. The
 * array should be declared in main() and include the values:
 *
 *	- 89, 95, 72, 83, 99, 54, 86, 75, 92, 73, 79, 75, 82, 73
 *
 * The variance() function should calculate and return the variance
 * of the data. The variance is obtained by subtracting the average
 * from each value in testvals, squaring the difference obtained,
 * adding their squares, and dividing by the number of elements
 * in testvals. The values returned from calcAvg() and variance()
 * should be displayed using printf() function calls in main().
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

int
ComputeAverage(int array[], int size);

int
ComputeVariance(int array[], int size, int average);

int
main()
{
	int testvals[] = { 89, 95, 72, 83, 99, 54, 86, 75, 92, 73, 79, 75, 82, 73, };
	int average = ComputeAverage(testvals, len(testvals));
	int variance = ComputeVariance(testvals, len(testvals), average);

	printf("Average: %d\n", average);
	printf("Variance: %d\n", variance);

	return 0;
}

int
ComputeAverage(int array[], int size)
{
	int result = 0;

	for (int i = 0; i < size; ++i)
	{
		result += array[i];
	}

	result /= size;

	return result;
}

int
ComputeVariance(int array[], int size, int average)
{
	int result = 0;
	int temp = 0;

	for (int i = 0; i < size; ++i)
	{
		temp = (array[i] - average);
		temp = temp * temp;
		result += temp;
	}
	result /= size;

	return result;
}

