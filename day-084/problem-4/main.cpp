/*
 * Given a one-dimensional array of integers numbers, 
 * write and test a function that prints the elements
 * in reverse order.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 5;

int
main()
{
	int TestCase[Size] = { 1, 2, 3, 4, 5, };

	printf("Array: { ");
	for (int i = len(TestCase) - 1; i >= 0; --i)
	{
		printf("%d, ", TestCase[i]);
	}
	printf("}\n");

	return 0;
}

