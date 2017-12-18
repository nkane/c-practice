/*
 * Using the following declaration:
 *
 * struct MonthDays
 * {
 *      char name[10];
 *      int days;
 * };
 *
 * Define an array of 12 structures of type MonthDays. Name the array convert[],
 * and initialize the array with the names of the 12 months in a year and the number
 * of days in each month.
 *
 * Include the above array in a program that displays the names and number of days
 * in each month.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

typedef struct _monthDays
{
    char name[10];
    int days;
} MonthDays;

void
DisplayMonthDays(MonthDays *md, int size);

int
main()
{
    MonthDays convert[12] = 
    {
        { "January", 31 },
        { "February", 28 },
        { "March", 31 },
        { "April", 30 },
        { "May", 31 },
        { "June", 30 },
        { "July", 31 },
        { "August", 31 },
        { "September", 30 },
        { "October", 31 },
        { "November", 30 },
        { "December", 31 },
    };

    DisplayMonthDays(convert, len(convert));

    return 0;
}

void
DisplayMonthDays(MonthDays *mdArray, int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("%s : days: %d\n", (char *)(mdArray + i)->name, (int)(mdArray + i)->days);
    }
}
