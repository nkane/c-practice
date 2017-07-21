/*
 * Modify Program 8.6 so that a high function is called that
 * determines the highest value in the passed array and
 * returns this value to the main program unit for display
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

int
FindHighestValue(int array[], int size);

int
main()
{
	int highest = 0;
	int value[Size] = { 98, 82, 67, 54, 78, 83, 95, 76, 68, 63, };
	double average, standardDeviation;

	highest = FindHighestValue(value, Size);
	average = FindAverage(value, Size);
	standardDeviation = StandardDeviation(value, Size, average);

	printf("Highest Value: %d\n", highest);

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

int
FindHighestValue(int array[], int size)
{
	int max = array[0];
	for (int i = 1; i < size; ++i)
	{
		if (max < array[i])
		{
			max = array[i];
		}
	}
	return (max);
}

