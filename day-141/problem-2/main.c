/*
 * Write a C program that accepts a user-entered date. Have the program calculate and
 * display the date of the next day.
 *
 */

#include <stdio.h>


typedef struct _date
{
    int month;
    int day;
    int year;
    int isLeapYear;
    int maxDays;
} Date;

void
GetDate(Date *d);

void
PrintDate(Date * d);

int
IsLeapYear(int year);

int
GetDaysInMonth(int month, int isLeapYear);

void
AddDay(Date *d);

int
main()
{

    Date d = { 0 };

    GetDate(&d);
    PrintDate(&d);

    return 0;
}

void
GetDate(Date *d)
{
    do {
        printf("Enter in year: ");
        scanf("%d", &d->year);
    } while (d->year <= 0);

    d->isLeapYear = IsLeapYear(d->year);

    do {
        printf("Enter in month: ");
        scanf("%d", &d->month);
    } while (d->month < 0 || d->month > 12);

    d->maxDays = GetDaysInMonth(d->month, d->isLeapYear);

    do {
        printf("Enter in day: ");
        scanf("%d", &d->day);
    } while (d->day > d->maxDays);

    AddDay(d);
}

void
PrintDate(Date * d)
{
    printf("%d/%d/%d\n", d->month, d->day, d->year);
}

int
IsLeapYear(int year)
{
    int result = 0;
    if ((year % 400) == 0)
    {
        result = 1;
    }
    else if ((year % 100) == 0)
    {
        result = 1;
    }
    else if ((year % 4) == 0)
    {
        result = 1;
    }
    return (result);
}

int
GetDaysInMonth(int month, int isLeapYear)
{
    int days;
    switch (month)
    {
        case 1:
        {
            days = 31;
        } break;

        case 2:
        {
            if (isLeapYear) 
            {
                days = 29;
            }
            else
            {
                days = 28;
            }
        } break;
        
        case 3:
        {
            days = 31;
        } break;

        case 4:
        {
            days = 30;
        } break;

        case 5:
        {
            days = 31;
        } break;

        case 6:
        {
            days = 30;
        } break;

        case 7:
        {
            days = 31;
        } break;

        case 8:
        {
            days = 31;
        } break;

        case 9:
        {
            days = 30;
        } break;

        case 10:
        {
            days = 31;
        } break;

        case 11:
        {
            days = 30;
        } break;

        case 12:
        {
            days = 31;
        } break;
    }
    return (days);
}

void
AddDay(Date *d)
{
    ++d->day;
    if (d->day > d->maxDays)
    {
        d->day = 1;
        ++d->month;
        if (d->month > 12)
        {
            d->month = 1;
            ++d->year;
        }
    }
}
