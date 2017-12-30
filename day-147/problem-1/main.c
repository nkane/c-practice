/*
 * Write a C function named diffDays() that calculates and returns the difference between two dates.
 * Each date is passed to the function as a struct using the following global structure:
 *
 *  struct Date
 *  {
 *      int month;
 *      int day;
 *      int year;
 *  };
 *
 *  The diffDays() function should make two calls to the days() function written for the previous
 *  day's exercise.
 *
 *  - NOTE(nick): last problem assumed 30 days per month
 *
 */

#include <stdio.h>

typedef struct _date
{
    int month;
    int day;
    int year;
} Date;

Date
GetInputDate();

int
DayDiffFromDates(Date beginDate, Date diffDate);

int
DiffDays(Date d1, Date d2);

void
DatePrint(Date d);

int
main()
{
    Date d1 = GetInputDate();
    Date d2 = GetInputDate();
    int dayDiff = DiffDays(d1, d2);

    DatePrint(d1);
    DatePrint(d2);

    printf("day diffs: %d\n", dayDiff);

    return 0;
}

Date
GetInputDate()
{
    Date d = (Date)
    { 
        .month = 0,
        .day = 0,
        .year = 0,
    };

    do {
        printf("Enter a month: ");
        scanf("%d", &d.month);
    } while (d.month < 0 || d.month > 12);

    do {
        printf("Enter a day: ");
        scanf("%d", &d.day);
    } while (d.day < 0 || d.day > 30);

    do {
        printf("Enter a year: ");
        scanf("%d", &d.year);
    } while (d.year < 0);

    return d;
}

int
DayDiffFromDates(Date beginDate, Date diffDate)
{
    int result = 0;
    int currentDiff = 0;

    // NOTE(nick): diff between years - default day for a year is 360 days
    currentDiff = (diffDate.year - beginDate.year);
    result += (currentDiff * 360);

    // NOTE(nick): diff between months - default days for a month is 30 days
    currentDiff = (diffDate.month - beginDate.month);
    result += (currentDiff * 30);

    // NOTE(nick: diff between days
    currentDiff = (diffDate.day - beginDate.day);
    result += currentDiff;

    return result;
}

int
DiffDays(Date d1, Date d2)
{
    Date defaultDate = (Date)
    {
        .month = 1,
        .day = 1,
        .year = 1900
    };
    int result = 0;
    int d1Days = DayDiffFromDates(defaultDate, d1);
    int d2Days = DayDiffFromDates(defaultDate, d2);
    result = d1Days - d2Days;
    return result;
}

void
DatePrint(Date d)
{
    printf("Date: %d/%d/%d\n", d.month, d.day, d.year);
}
