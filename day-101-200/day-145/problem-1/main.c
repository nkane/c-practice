/*
 * Construct a set of parrallel arrays consisting of 10 integer identifcation numbers and 10
 * pay rates. Then, determine the identification number that correspond to the highest pay rate.
 * Make sure to locate the highest pay rate by sorting the pay rate array so that the highest pay
 * rate has a subscript value of 0.
 *
 * What problems do you encounter in determining the correct identification number
 * when you sort the pay rate array? 
 *
 * NOTE(nick):
 * - The issue with sorting the pay rate array is that the arrays are not longer "parralell arrays";
 *   additionally, we cannot determine the initial order after sorting.
 *
 */

#include <stdio.h>

#define SIZE 10

#define len(array)(sizeof(array)/sizeof(array[0]))

int
FindMaxIndex(int *array, int size);

int intCompareFunc(const void *x, const void *y);

int
main()
{
    int ids[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, };
    int payRate[SIZE] = { 1, 35, 100, 15, 16, 37, 101, 200, 2, 9, };

    // get index of highest pay rate before sorting
    int highPayRateIndex = FindMaxIndex(payRate, len(payRate));

    // sort payRate
    qsort(payRate, len(payRate), sizeof(int), intCompareFunc);

    // NOTE(nick): cannot find corresponding id in the ids array after sorting!

    printf("id found before sorting: %d\n", highPayRateIndex);

    system("pause");

    return 0;
}

int
FindMaxIndex(int *array, int size)
{
    int index = -1;
    int result = 0;
    for (int i = 0; i < size; ++i)
    {
        if (result < *(array + i))
        {
            result = *(array + i);
            index = i;
        }
    }
    return index;
}

int intCompareFunc(const void *x, const void *y)
{
    return (*(int *)y - *(int *)x);
}

