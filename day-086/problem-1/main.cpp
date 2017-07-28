/*
 * In many statistical analysis programs, data values that are considerably
 * outside the range of the majoirty of values are simply dropped from consideration.
 * Using this information, write a C program that accepts up to 10 double-percision
 * values from a user and determines and displays the average and standard deviation
 * of the input values. All values that are more than 4 standard deviations
 * away from the computed average are to be displayed and dropped from any further
 * calculation, and a new average and standard deviation should be computed
 * and displayed.
 *
 */

#include <math.h>
#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 3;

global_variable const int Cut_Off = 4;
global_variable const double Cut_Off_Value = -1;

global_variable bool Is_Valid = false;

double
FindAverage(double array[], int size);

double
StandardDeviation(double array[], int size, double average);

double
SingleDeviation(double value, double average);

int
main()
{
	double TestCase[Size] = { 0.0 };
	double average = 0.0;
	double standardDeviation = 0.0;

	for (int i = 0; i < len(TestCase); ++i)
	{
		printf("Enter in a value for [%d]: ", i);
		scanf("%lf", &TestCase[i]);
	}

	while (!Is_Valid)
	{
		average = FindAverage(TestCase, len(TestCase));
		standardDeviation = StandardDeviation(TestCase, len(TestCase), average);
		printf("Average: %lf\n", average);
		printf("Standard Deviation: %lf\n", standardDeviation);
	}


	return 0;
}

double
FindAverage(double array[], int size)
{
	double result = 0.0;
	int actualSize = 0;
	for (int i = 0; i < size; ++i)
	{
		// NOTE(nick): making an input assumption here - values should be greater than or equal to 0
		if (array[i] >= 0.0)
		{
			result += array[i];
			++actualSize;
		}
	}
	result /= actualSize;
	return (result);
}

double
StandardDeviation(double array[], int size, double average)
{
	double result = 0.0;
	double currentResult = 0.0;
	int cutOffCount = 0;
	int actualSize = 0;
	for (int i = 0; i < size; ++i)
	{
		if (array[i] >= 0.0)
		{
			currentResult = SingleDeviation(array[i], average);
			++actualSize;
			result += pow((array[i] - average), 2);
		}
		if (currentResult > Cut_Off)
		{
			array[i] = Cut_Off_Value;
			++cutOffCount;
		}
	}
	if (cutOffCount == 0)
	{
		Is_Valid = true;
	}
	result = sqrt(result / actualSize);
	return (result);
}

double
SingleDeviation(double value, double average)
{
	double result = 0.0;
	result = pow((value - average), 2);
	result = sqrt(result);
	return (result);
}

