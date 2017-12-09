/*
 * Modify the findMax() function to locate the minimum value of the passed array.
 * Write the function using only pointers and rename the function findMin()
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

int
FindMax(int *array, int size);

int
FindMin(int *array, int size);

void
PrintArray(int *array, int size);

int
main()
{
    srand(time(NULL));
    int testCase[10] = { 0 };
    int i;
    for (i = 0; i < len(testCase); ++i)
    {
        *(testCase + i) = rand();
    }

    PrintArray(testCase, len(testCase));

    int min = FindMin(testCase, len(testCase));
    int max = FindMax(testCase, len(testCase));

    printf("Min: %d\n", min);
    printf("Max: %d\n", max);

    return 0;
}

int
FindMax(int *array, int size)
{
    int result = *(array + 0);
    int i;
    for (i = 0; i < size; ++i)
    {
        if (result < *(array + i))
        {
            result = *(array + i);
        }
    }
    return result;
}

int
FindMin(int *array, int size)
{
    int result = *(array + 0);
    int i;
    for (i = 0; i < size; ++i)
    {
        if (result > *(array + i))
        {
            result = *(array + i);
        }
    }
    return result;
}

void
PrintArray(int *array, int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("Array[%d] : %d\n", i, *(array + i));
    }
}
