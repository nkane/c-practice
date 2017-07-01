/*
 * Write a C function named yrCalc() that accepts a longer integer representing the
 * total number of days from the day 1/1/1900 and the addresses of the variable year,
 * month, and day. The function is to calculate the current year, month, and day for
 * the given number of days and write these values directly in the respective variables
 * using the passed addresses. FOr this program assume that each year has 365 days
 * and each month has 30 days.
 *
 */

#include <stdio.h>

void
ComputeYear(int days, int *year, int *month, int *day);

int
main()
{
	int year = 1900, month = 1, day = 1;
	long int dayInput = 0;

	printf("Enter in the amount of days: ");
	scanf("%ld", &dayInput);
	
	ComputeYear(dayInput, &year, &month, &day);

	printf("Date: %d/%d/%d\n", month, day, year);

	return 0;
}

void
ComputeYear(int days, int *year, int *month, int *day)
{
	while (days > 0)
	{
		if (days >= 365) 
		{
			*year += 1;
			days -= 365;
		}
		else if (days >= 30)
		{
			*month += 1;
			days -= 30;
		}
		else 
		{
			*day += 1;
			--days;
		}
	}
}

