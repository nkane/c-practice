/*
 * Write a C program to reverse the digits of a positive integer number. For example,
 * if number 8735 is entered, the number displayed should be 5378. (Hint: Use a do
 * statement and continuously strip off and display the units digits of the number. If
 * the variable num initially contains the number entered, the units digit is obtained
 * as (num % 10). After a units digit is displayed dividing the number by 10 sets up
 * the number for the next interation. Thus, (8735 % 10) is 5 and (8735 / 10) is 873.
 * The do statement should continue as long as the remaining number is not 0.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable bool Running = true;

int
main()
{
	int input = 0;
	printf("Enter in a number to reverse:\n");
	scanf("%d", &input);

	do {
		if (input > 0)
		{

			printf("%d", (input % 10));
			input /= 10;
		}
		else 
		{
			Running = false;
		}

	} while(Running);

	return 0;
}
