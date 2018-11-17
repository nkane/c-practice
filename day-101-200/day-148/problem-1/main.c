/*
 * Write a C function named larger() that returns the later date of any two dates
 * passed to it. For example, if the dates 10/9/2001 and 11/3/2001 are passed to larger(),
 * the second date would be returned.
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
DateGetInput();

Date
DateLarger(Date d1, Date d2);

Date
DateLargerHardCheck(Date d1, Date d2);

void
DateCopy(Date *dp, Date d);

void
DatePrint(Date d);

int
DayDiffFromDates(Date beginDate, Date diffDate);

int
main()
{
    Date d1 = DateGetInput();
    Date d2 = DateGetInput();
    Date larger = DateLargerHardCheck(d1, d2);

    DatePrint(larger);

    larger = DateLarger(d1, d2);

    DatePrint(larger);

    return 0;
}

Date
DateGetInput()
{
    Date r = (Date)
    {
        .month = 0,
        .day = 0,
        .year = 0
    };

    do {
        printf("Enter a month: ");
        scanf("%d", &r.month);
    } while (r.month < 0 || r.month > 12);

    do {
        printf("Enter a day: ");
        scanf("%d", &r.day);
    } while (r.day < 0 || r.day > 30);

    do {
        printf("Enter a year: ");
        scanf("%d", &r.year);
    } while (r.year < 1900);

    return r;
}

Date
DateLarger(Date d1, Date d2)
{
    Date r = (Date)
    {
        .month = 0,
        .day = 0,
        .year = 0
    };

    Date defaultDate = (Date)
    {
        .month = 1,
        .day = 1,
        .year = 1900
    };

    int d1Days = DayDiffFromDates(defaultDate, d1);
    int d2Days = DayDiffFromDates(defaultDate, d2);
    
    if (d1Days > d2Days)
    {
        DateCopy(&r, d1);
    }
    else
    {
        DateCopy(&r, d2);
    }

    return r;
}

// NOTE(nick): hard checking instead of using a point of time and obtaining day difference
Date
DateLargerHardCheck(Date d1, Date d2)
{
    Date r = (Date)
    {
        .month = 0,
        .day = 0,
        .year = 0
    };

    if (d1.year > d2.year)
    {
        DateCopy(&r, d1);
    }
    else if (d1.year < d2.year)
    {
        DateCopy(&r, d2);
    }
    else
    {
        // NOTE(nick): years are equal - check month
        if (d1.month > d2.month)
        {
            DateCopy(&r, d1);
        }
        else if (d1.month < d2.month)
        {
            DateCopy(&r, d2);
        }
        else
        {
            // NOTE(nick): years and month are equal - check day
            if (d1.day > d2.day)
            {
                DateCopy(&r, d1);
            }
            else if (d1.day < d2.day)
            {
                DateCopy(&r, d2);
            }
        }
    }

    return r;
}

void
DateCopy(Date *dp, Date d)
{
    dp->month = d.month;
    dp->day = d.day;
    dp->year = d.year;
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

void
DatePrint(Date d)
{
    printf("Date: %d/%d/%d\n", d.month, d.day, d.year);
}
