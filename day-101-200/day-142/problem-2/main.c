/*
 * Using the structured defined in the previous question, write a C program that accepts a
 * month from a user in numeric form and displays the name of the month and the number of
 * days in the month. Thus, in response to an input of 3, the program displays March has
 * 31 days.
 *
 */

#include <stdio.h>

typedef struct _monthDays
{
    char name[10];
    int days;
} MonthDays;

int
main()
{
    int input = 0;
    MonthDays md[12] = 
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

    do {
        printf("Enter in the month number: ");
        scanf("%d", &input);
    } while (input <= 0 || input > 12);
    --input;

    printf("Month: %s - days: %d\n", (md + input)->name, (md + input)->days);

    return 0;
}
