/*
 * 	Write and execute a C program that calculates and displays the number
 *	of minutes in a year.
 */

#include <stdio.h>

#define DAYS_IN_YEAR 365
#define HOURS_IN_DAY 24
#define MINUTES_PER_HOUR 60

int CalculateMinutes(int days, int hourInDay, int minutesPerHour);

int main(void)
{
	int minutesInYear = CalculateMinutes(DAYS_IN_YEAR, HOURS_IN_DAY, MINUTES_PER_HOUR);

	printf("Days in Year: %d\n", DAYS_IN_YEAR);
	printf("Hours in Day: %d\n", HOURS_IN_DAY);
	printf("Minutes per Hour: %d\n", MINUTES_PER_HOUR);
	printf("Total minutes in a year: %d\n", minutesInYear);

	return 0;
}

int CalculateMinutes(int days, int hourInDay, int minutesPerHour)
{
	// totalDaysInHours = day * day hours
	// totalMinutes = totalDaysInHours * minutesPerHour
	int totalDaysInHours = days * hourInDay;
	int totalMinutes = totalDaysInHours * minutesPerHour;
	return totalMinutes;
}
