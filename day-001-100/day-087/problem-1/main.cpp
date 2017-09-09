/*
 * Given a one-dimensional array of double-percision numbers
 * named num, write a function that determines the sum of the numbers
 * with the following conditions:
 *
 * 	1) use repetition for one function
 * 	2) using recursion for antoher function (hint: if n = 1,
 * 	   then the sum is num[0]; otherwise, the sum is num[n]
 * 	   plus the sum of the first (n - 1) elements.)
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 3;

double
LoopSum(double array[], int size);

double
RecursiveSum(double array[], int size);

int
main()
{
	double TestCase[Size] = 
	{
		1.05,
		2.10,
		3.15,
	};

	printf("Loop Sum: %lf\n", LoopSum(TestCase, len(TestCase)));
	printf("Recursive Sum: %lf\n", RecursiveSum(TestCase, len(TestCase) - 1));
	
	return 0;
}

double
LoopSum(double array[], int size)
{
	double result = 0.0;
	for (int i = 0; i < size; ++i)
	{
		result += array[i];
	}
	return (result);
}

double
RecursiveSum(double array[], int size)
{
	double result = 0.0;
	if (size == 0)
	{
		return array[size];
	}
	return array[size] + RecursiveSum(array, size - 1);
}

