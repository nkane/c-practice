/*
 * Write and run a C program that request a day value. Have your program accept only day
 * values between 1 and 31.
 */

#include <stdio.h>

#define global_variable static

global_variable const int MinDay = 1;
global_variable const int MaxDay = 31;

int
main() 
{
	int dayValue = 0;

	do {
		printf("Enter in a day value (e.g., 1 - 31):\n");
		scanf("%d", &dayValue);
	} while(!((dayValue >= MinDay) && (dayValue <= MaxDay)));

	printf("Day value entered: %d\n", dayValue);

	return 0;
}

