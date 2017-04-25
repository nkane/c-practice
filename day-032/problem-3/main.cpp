/*
 * Write a C program that takes 8 input numbers and computes the total sum
 * of the eight numbers. 
 */ 

#include <stdio.h>

#define global_variable static

global_variable const int Input_Max = 8;

int
main()
{
	int i = 0;
	float currentNumber = 0;
	float total = 0;

	while (i < Input_Max)
	{
		printf("Enter in a number:\n");
		scanf("%f", &currentNumber);
		total += currentNumber;
		++i;
	}

	printf("The sum of the numbers is: %.2f\n", total);

	return 0;
}
