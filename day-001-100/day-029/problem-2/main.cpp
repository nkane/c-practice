/*
 * All years that are evenly divisible by 400 or are evenly divisible by 4
 * and not evenly divisible by 100 are leap years. For example, since 1600
 * is evenly divisible by 400, the year 1600 was a leap year. Similary, since
 * 1988 is evenly divisible by 4 but not by 100, the year 1988 was also a leap
 * year. Using this information, write a C program that accepts the year as user
 * input, determine if the year is a leap year, and display an appropriate message
 * that tells the user if the entered year is or is not a leap year. 
 */

#include <stdio.h>

struct Date
{
	int Year;
	bool LeapYear;
};

inline Date
CreateDate();

inline bool
IsLeapYear(Date *);

inline void
PrettyPrint(Date *);

int
main()
{
	Date D = CreateDate();
	PrettyPrint(&D);

	return 0;
}

inline Date
CreateDate()
{
	Date D = {};

	printf("Enter in a year:\n");
	scanf("%d", &D.Year);

	D.LeapYear = IsLeapYear(&D);

	return D;
}

inline bool
IsLeapYear(Date *d)
{
	bool result = false;
	result = (d->Year % 4 == 0 && d->Year % 100 > 0  || d->Year % 400 == 0) ? true : false;
	return result;
}

inline void
PrettyPrint(Date *d)
{
	if (d->LeapYear)
	{
		printf("Year %d - is a leap year!\n", d->Year);
	}
	else 
	{
		printf("Year %d - is NOT a leap year!\n", d->Year);
	}
}
