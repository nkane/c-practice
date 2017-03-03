/*
 * Write a C program that stores the integer value 15 in a variable named num1
 * and the integer value 18 in the variable num2. (Make sure to declare these
 * two variables as integers.) Have your program calculate the total of these
 * numbers and their average. The total should be stored in the variable named
 * total and the average in the variable named average. (Use the statement
 * average = total / 2.0; to calculate the average.) Use the printf() function
 * to display the total and average.
 */

#include <stdio.h>

inline float SumInts(int, int);
inline float AverageInts(int, int);

int main(void)
{
	int valueOne = 15;
	int valueTwo = 18;

	printf("Value One: %d\nVaueTwo: %d\n", valueOne, valueTwo);
	printf("Total is: %f\n", SumInts(valueOne, valueTwo));
	printf("Average is: %f\n", AverageInts(valueOne, valueTwo));

	return 0;
}

inline float SumInts(int x, int y)
{
	float result = x + y;
	return result;
}

inline float AverageInts(int x, int y)
{
	float result = (((float)x + (float)y) / 2.0f);
	return result;
}
