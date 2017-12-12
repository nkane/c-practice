/*
 * Write a C function named trimfrnt() that deletes all leading blanks from a string.
 * Writ write the function using pointers.
 *
 */

#include <stdio.h>

#define SIZE 256

#define len(array)(sizeof(array)/sizeof(array[0]))

void
TrimFront(char *stringBuffer, int size);

int
StringLength(char *stringBuffer, int size);

int
main()
{
    char testCaseOne[SIZE] = "   this is a test";

    printf("before trim: %s\n", testCaseOne);
    TrimFront(testCaseOne, StringLength(testCaseOne, len(testCaseOne)));
    printf("after  trim: %s\n", testCaseOne);

    char testCaseTwo[SIZE] = "this is a test";
    printf("before trim: %s\n", testCaseTwo);
    TrimFront(testCaseTwo, StringLength(testCaseTwo, len(testCaseTwo)));
    printf("after  trim: %s\n", testCaseTwo);

    char testCaseThree[SIZE] = " this is a test";
    printf("before trim: %s\n", testCaseThree);
    TrimFront(testCaseThree, StringLength(testCaseThree, len(testCaseThree)));
    printf("after  trim: %s\n", testCaseThree);
    
    return 0;
}

void
TrimFront(char *stringBuffer, int size)
{
    int i;
    int blankShift = 0;
    unsigned char stillBlank = 1;
    for (i = 0; i < size && stillBlank == 1; ++i)
    {
        if (*(stringBuffer + i) == ' ')
        {
            blankShift++;
        }
        else
        {
            stillBlank = 0;
        }
    }

    if (blankShift > 0)
    {
        int j;
        for (j = 0; (blankShift + j) < size; ++j)
        {
            *(stringBuffer + j) = *(stringBuffer + (blankShift + j));
        }
    }
}

int
StringLength(char *stringBuffer, int size)
{
    int i;
    for (i = 0; *(stringBuffer + i) != '\0' && i < size; ++i);
    return i + 1;
}

