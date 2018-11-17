/*
 * Write a function that will accept 6 lines of user-input text and
 * store the entered lines as 6 individual strings. Use a pointer 
 * array in your function.
 *
 */

#include <stdio.h>

void
WriteToStringBufferArray(char stringBufferArray[6][256], int x, int y);

int
main()
{
    char stringBufferArray[6][256] = { 0 };

    WriteToStringBufferArray(stringBufferArray, 256, 6);

    int i;
    for (i = 0; i < 6; ++i)
    {
        printf("string[%d] -> %s\n", i, *(stringBufferArray + i));
    }

    return 0;
}

void
WriteToStringBufferArray(char stringBufferArray[6][256], int x, int y)
{
    int i;
    for (i = 0; i < y; ++i)
    {
        printf("Enter in a string: ");
        gets(&(**(stringBufferArray + i)));
    }
}
