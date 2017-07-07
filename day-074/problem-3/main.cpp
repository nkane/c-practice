/*
 * Write a C program to input the following integer numbers into an array named
 * grades:
 *
 * 	89, 95, 72, 83, 99, 54, 86, 75, 92, 73, 79, 75, 82, 73
 *
 * As each number is input, add the numbers to the total. After all numbers are
 * input and the total is obtained, calculate the average of the numbers and use
 * the average to determine the deviation of each value from the average. Store
 * each deviation in an array named deviation. Each deviation is obtained
 * as the element value less the average of all the data. Have the program
 * display each diviation alongside its corresponding element from the grades
 * array.
 *
 * Calculate the variance of data - the variance is obtained by squaring each
 * individual deviation and dividing the sum of the squared deviations by 
 * the number of deviations.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define array_size(array)(sizeof(array)/sizeof(array[0]))
#define square(value)(value * value)

#define global_variable static

global_variable const int Size = 14;

int
main()
{
	int Grades[Size] = { 0 };
	int Deviation[Size] = { 0 };
	int variance = 0;
	int total = 0;
	int average = 0;

	for (int i = 0; i < array_size(Grades); ++i)
	{
		printf("Enter in the grade [%d]: ", i);
		scanf("%d", &Grades[i]);
		total += Grades[i];
	}

	average = (total / array_size(Grades));
	printf("Average: %d\n", average);

	for (int i = 0; i < array_size(Grades); ++i)
	{
		Deviation[i] = abs(Grades[i] - average);
		printf("Grade: %d \t Deviation: %d\n", Grades[i], Deviation[i]);
		variance += square(Deviation[i]);
	}

	variance /= array_size(Deviation);

	printf("Variance: %d\n", variance);

	return 0;
}
