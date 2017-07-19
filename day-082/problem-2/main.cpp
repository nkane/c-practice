/*
 * Rewrite Program 8.6 to determine the average and standard
 * deviation of the following list of 15 grades:
 *
 * 	- 68, 72, 78, 69, 85, 98, 95, 75, 77, 82, 84, 91, 89, 65, 74
 *
 */

#include <stdio.h>
#include <math.h>

#define global_variable static

global_variable const int Size = 15;

double
FindAverage(int array[], int size);

double
StandardDeviation(int array[], int size, double average);

int
main()
{
	int values[Size] = { 68, 72, 78, 69, 85, 98, 95, 75, 77, 82, 84, 91, 89, 65, 74, };

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

