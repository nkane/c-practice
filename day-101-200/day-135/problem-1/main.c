/*
 * Replace the while statement in Program 11.5 with a for statement.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

#define SIZE 5

int
main()
{
    int nums[SIZE] = { 16, 54, 7, 43, -5, };
    int total = 0, *nPtr;

    for (nPtr = nums; nPtr < (nums + len(nums)); nPtr++)
    {
        total += *nPtr;
    }
    printf("The total of the array elements is %d\n", total);

    return 0;
}
