/*
 * Write a function named date() that accepts an integer of the form 
 * yyyymmdd, such as 20070412; determines the corresponding month,
 * day, and year, and returns these three values to the calling function.
 * For example, if date is called using the statement
 *
 * 	date(20120412, &month, &day, &year);
 *
 * the number 4 should be returned in month, the number 11 in day, and
 * the number 2012 in year.
 *
 */

#include <stdio.h>

void
Date(int date, int *month, int *day, int *year);

int
main()
{
	int date = 20070412;
	int month, day, year;

	Date(date, &month, &day, &year);

	printf("Month: %d\n", month);
	printf("Day: %d\n", day);
	printf("Year: %d\n", year);

	return 0;
}

void
Date(int date, int *month, int *day, int *year)
{
	(*year) = (date / 10000);
	(*month) = ((date - (*year) * 10000) / 100);
	(*day) = (((date - (*year) * 10000)) - (*month * 100));
}
