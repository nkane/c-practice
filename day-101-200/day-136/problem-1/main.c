/*
 * Write a C program that stores the following numbers in an array named miles:
 * 15, 22, 16, 18, 27, 23, 20. Have your program copy the data stored in miles
 * to another array named dist and then display the values in the dist array.
 *
 */

#include <stdio.h>

#define SIZE 7
#define len(array)(sizeof(array)/sizeof(array[0]))

void
CopyArray(int *src, int *dest, int size); 

void
DisplayArray(int *array, int size);

int
main()
{
    int miles[SIZE] = { 15, 22, 16, 18, 27, 23, 20, };
    int dist[SIZE] = { 0 };

    CopyArray(miles, dist, len(miles));
    DisplayArray(dist, len(dist));

    return 0;
}


void
CopyArray(int *src, int *dest, int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        *(dest + i) = *(src + i);
    }
}

void
DisplayArray(int *array, int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("Array [%d] : %d\n", i, *(array + i));
    }
}
