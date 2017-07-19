/*
 * Modify Progrma 8.6 so that the grades are entered
 * into the values array using a function named 
 * entervalues()
 *
 */

#include <stdio.h>
#include <math.h>

#define global_variable static

global_variable const int Size = 10;

void
EnterValues(int array[], int size);

double
FindAverage(int array[], int size);

double
StandardDeviation(int array[], int size, double average);

int
main()
{
	//double values[Size] = { 98, 82, 67, 54, 78, 83, 95, 76, 68, 63, };
	int values[Size] = { 0 };

	EnterValues(values, Size);

	double average, standardDeviation;

	average = FindAverage(values, Size);
	standardDeviation = StandardDeviation(values, Size, average);

	printf("The average of the numbers is %5.2lf\n", average);
	printf("The standard deviation of the numbers is: %5.2lf\n", standardDeviation);

	return 0;
}

void
EnterValues(int array[], int size)
{
	int i = 0;
	for (i = 0; i < size; ++i)
	{
		printf("Enter in [%d] value: ", i);
		scanf("%d", &array[i]);
	}
}

double
FindAverage(int array[], int size)
{
	int i;
	double sum = 0.0;

	for (i = 0; i < size; ++i)
	{
		sum += array[i];
	}

	return (sum / size);
}

double
StandardDeviation(int array[], int size, double average)
{
	int i;
	double sum = 0.0;
	for (i = 0; i < size; ++i)
	{
		sum += pow((array[i] - average), 2);
	}

	return (sqrt(sum / size));
}

