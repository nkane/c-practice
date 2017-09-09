/*
 * Write a program that displays the following two prompts:
 * "Enter a month (use 1 for Jan, etc):"
 * "Enter a day of the month:"
 * 
 * Your program should accept and store a number in a variable
 * in response to the first prompt, and accept and store a number
 * in a variable in response to the second prompt. If
 * the month entered is not between 1 and 12 inclusive, the program
 * should print a message informing the user that an invalid month
 * has been entered. If the day entered is not between 1 and 31 inclusive,
 * the program should print a message informing the user that an invalid
 * day has been entered.
 *
 * What will your program do if the user types a number with a decimal point
 * for the month? How can you ensure that your if statements check for an
 * integer number?
 *
 * In a non-leap year, February has 28 days; the months January, March, May
 * July, August, October, and December has 31 days; and all the other months
 * have 30 days. Using this information, the program needs to display a message
 * when an invalid day is entered for a user-entered month - for this program
 * ignore leap years.
 */

#include <stdio.h>

const char* Months[12] =
{
	"Jan",
	"Feb",
	"Mar",
	"Apr",
	"May",
	"Jun",
	"Jul",
	"Aug",
	"Sep",
	"Oct",
	"Nov",
	"Dec",
};

struct Date
{
	int MonthIndex;
	int Day;
};

inline Date*
CreateDate();

inline bool
IsValidDate(Date *);

inline void
PrettyPrint(Date);

int
main()
{
	Date *D = CreateDate();

	if (D)
	{
		PrettyPrint(*D);
	}
	else
	{
		// bad date entered!
		printf("Bad Date Entered!\n");
	}

	return 0;
}

inline Date*
CreateDate()
{
	Date *D = &Date{};
	printf("Enter a month (use 1 for Jan, etc):\n");
	scanf("%d", &D->MonthIndex);

	// adjust index to 0 based
	--D->MonthIndex;

	printf("Enter a day of the month:\n");
	scanf("%d", &D->Day);

	if (!IsValidDate(D))
	{
		D = NULL;
	}

	return D;
}

inline bool
IsValidDate(Date *d)
{
	bool result = false;

	if (d->MonthIndex >= 0 && d->MonthIndex <= 12)
	{
		if (d->Day > 0) 
		{
			// 0 based index
			switch (d->MonthIndex)
			{
				// Feb check
				case 1:
				{
					if (d->Day <= 28)
					{
						result = true;
					}
				} break;

				case 0:
				case 2:
				case 4: 
				case 5:
				case 6:
				case 7:
				case 9: 
				case 11:
				{
					if (d->Day <= 31)
					{
						result = true;
					}
				} break;
				
				default:
				{
					if (d->Day > 0 && d->Day <= 30)
					{
						result = true;
					}
				} break;
			}
		}
	}

	return result;
}

inline void
PrettyPrint(Date d)
{
	printf("Month -> %s\n", Months[d.MonthIndex]);
	printf("Day: %d\n", d.Day);
}

