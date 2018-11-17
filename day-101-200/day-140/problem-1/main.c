/*
 * Write a C program that prompts a user to input the current month, day, and year.
 * Store the data entered in a suitably defined structure and display the date in an
 * appropriate manner.
 *
 * Add a prompt for the current time in hours, minutes, and seconds.
 *
 */

#include <stdio.h>

typedef struct _DateTime
{
    unsigned char Day;
    unsigned char Month;
    unsigned int Year;
    unsigned char Hours;
    unsigned char Minutes;
    unsigned char Seconds;
} DateTime;

void
GetDateTime(DateTime *result);

void
PrintDateTime(DateTime dt);

int
main()
{
    DateTime current = { 0 };

    GetDateTime(&current);
    PrintDateTime(current);

    return 0;
}

// NOTE(nick): no input validation is done in this function!
void
GetDateTime(DateTime *result)
{
    printf("Enter the month: ");
    scanf("%d", (int *)&result->Month);

    printf("Enter the day: ");
    scanf("%d", (int *)&result->Day);

    printf("Enter the year: ");
    scanf("%d", &result->Year);

    printf("Enter hours: ");
    scanf("%d", (int *)&result->Hours);

    printf("Enter minutes: ");
    scanf("%d", (int *)&result->Minutes);

    printf("Enter seconds: ");
    scanf("%d", (int *)&result->Seconds);
}

void
PrintDateTime(DateTime dt)
{
    printf("Date: %d/%d/%d\n", dt.Month, dt.Day, dt.Year);
    printf("Time: %d:%d:%d\n", dt.Hours, dt.Minutes, dt.Seconds);
}

