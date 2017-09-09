/*
 * Write and run a C program that request both a month and day value. Only month values
 * between 1 and 12 should be accepted. Further, day values between 1 and 28 should only
 * be accepted for month 2 (February); day values between 1 and 30 should only be
 * accepted for months 4, 6, 9, and 11 (April, June, September, and November); and only
 * days values between 1 and 31 should be accepted for all remaining months. (hint: use a
 * switch statement).
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Month_Min 		= 1;
global_variable const int Month_Max 		= 12;

global_variable const int Day_Min 		= 1;
global_variable const int Day_Normal_Max 	= 31;
global_variable const int Day_Abnormal_Max 	= 30;
global_variable const int Day_Unusual_Max	= 28;


struct Date 
{
	int Month;
	int Day;
};

inline Date
CreateDate(int, int);

inline void
PrettyPrintD(Date *);

inline bool
ValidDateRange(int, int);

int
main() 
{
	int month = 0,
	    day = 0;


	do {
		printf("Enter in month range (e.g., 1 - 12):\n");
		scanf("%d", &month);

		printf("Enter in day range (depends on month):\n");
		scanf("%d", &day);
	} while(!ValidDateRange(month, day));

	Date D = CreateDate(month, day);
	PrettyPrintD(&D);

	return 0;
}

inline Date
CreateDate(int m, int d)
{
	Date D = 
	{
		m,
		d,
	};

	return D;
}

inline void
PrettyPrintD(Date *d)
{
	printf("Month: %d - Day: %d\n", d->Month, d->Day);
}

inline bool
ValidDateRange(int month, int day)
{
	if (!((month >= Month_Min) && (month <= Month_Max)))
	{
		return false;
	}
	
	if (!(day >= Day_Min))
	{
		return false;
	}
	
	switch (month)
	{
		case 2:
		{
			// February
			if (!(day <= Day_Unusual_Max))
			{
				return false;
			}
		} break;
		
		case 4:
		case 6:
		case 9:
		case 11:
		{
			// April, June, September, and November
			if (!(day <= Day_Abnormal_Max))
			{
				return false;
			}
		}

		default:
		{
			if (!(day <= Day_Normal_Max))
			{
			}
		} break;
	}

	return true;
}
