/*
 * Write a C program that has a declaration in main() to store the following numbers
 * into an array named rates: 6.5, 7.2, 7.5, 9.3, 9.6, 9.8, 10.0. There should be
 * a function call to show() that accepts rates in a parameter named rates and then
 * displays the numbers using the pointer notation *(rates + i).
 *
 * Modify the show() function written to alter the address in rates. Use the expression
 * *rates rather than *(rates + i) to retrieve the correct element.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

void
Show(float *rates, int size);

void
ShowAlt(float *rates, int size);

int
main()
{
    float rates[] = { 6.5f, 7.2f, 7.5f, 9.3f, 9.6f, 9.8f, 10.0f, };

    Show(rates, len(rates));
    ShowAlt(rates, len(rates));

    return 0;
}

void
Show(float *rates, int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf(" %6.2f, ", *(rates +i));
    }
    printf("\n\n");
}

void
ShowAlt(float *rates, int size)
{
    float *end = (rates + (size));
    for (rates; rates < end; rates++)
    {
        printf(" %6.2f, ", *rates);
    }
}
