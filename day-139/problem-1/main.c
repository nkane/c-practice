/*
 * Write a C function that displays the days of the week corresponding to a user-entered
 * input number between 1 and 7. That is, in response to an input of 2, the program
 * displays the name Monday. Use an array of pointers in the function.
 *
 */

#include <stdio.h>

void
DisplayDay(char **days, int x);

int
main()
{
    int input = 0;
    char *days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", };

    printf("Enter in day number: ");
    scanf("%d", &input);

    DisplayDay(days, input);

    return 0;
}

void
DisplayDay(char **days, int x)
{
    char *day = *(days + (x - 1));
    printf("The day is %s\n", day);   
}

