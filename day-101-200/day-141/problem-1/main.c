/*
 * Write a C program that accepts a user-entered time in hours and minutes. Have the
 * program calculate and display the time one minute later.
 *
 */

#include <stdio.h>

typedef struct _time
{
    unsigned char hours;
    unsigned char minutes;
} Time;

void
GetTime(Time *t);

void
PrintTime(Time *t);

int
main()
{
    Time t = { 0 };

    GetTime(&t);
    PrintTime(&t);

    return 0;
}

void
GetTime(Time *t)
{
    do {
        printf("Enter in hours: ");
        scanf("%d", (int *)&t->hours);
    } while (t->hours < 0 || t->hours >= 24);

    do {
        printf("Enter in the minutes: ");
        scanf("%d", (int *)&t->minutes);
    } while (t->minutes < 0 || t->minutes >= 60);

    ++t->minutes;

    if (t->minutes >= 60)
    {
        t->minutes = 0;
        if ((t->hours + 1) >= 24)
        {
            t->hours = 0;
            t->minutes = 1;
        }
        else
        {
            ++t->hours;
        }
    }
}

void
PrintTime(Time *t)
{
    printf("Hours: %d\n", t->hours);
    printf("Minutes: %d\n", t->minutes);
}
