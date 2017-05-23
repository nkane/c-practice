/*
 * Write a function that accepts an integer argument, determines whether the passed
 * integer is even or odd, and displays an appropriate message indicating the result of its
 * determination.
 *
 */

#include <stdio.h>

inline bool
IsEven(int);

int
main()
{
	int x = 0;

	printf("Enter in a integer value:\n");
	scanf("%d", &x);

	printf("Value: %d - is .... ", x);

	if (IsEven(x))
	{
		printf("even!\n");
	}
	else
	{
		printf("odd!\n");
	}

	return 0;
}

inline bool
IsEven(int x)
{
	bool result = (x % 2) == 0 ? true : false;
	return result;
}

