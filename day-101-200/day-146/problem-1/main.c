/*
 * Write a C function named days() that determines the number of days from the date
 * 1/1/1900 for any date passed as a structure. Use the following Date structure:
 *
 * struct Date
 * {
 *      int month;
 *      int day;
 *      int year;
 * };
 *
 * In writing the days() function, use the convention that all years have 360 days and
 * each month consist of 30 days. The function should return the number of days for any
 * date structure passed to it.
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
RequestDateInput();

int
DayDiffFromDates(Date beginDate, Date diffDate);

int
main()
{
    Date defaultDate = (Date)
        {
            .month = 1,
            .day = 1, 
            .year = 1900
        };

    Date inputDate = RequestDateInput();

    printf("Day difference: %d\n", DayDiffFromDates(defaultDate, inputDate));

    system("pause");

    return 0;
}

Date
RequestDateInput()
{
    Date result = { 0 };

    do {
        printf("Input a month: ");
        scanf("%d", &result.month);
    } while (result.month > 12 || result.month < 1);

    do {
        printf("Input a day: ");
        scanf("%d", &result.day);
    } while (result.day > 30 || result.day < 1);

    do {
        printf("Input a year: ");
        scanf("%d", &result.year);
    } while (result.year < 1900);

    return result;
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
