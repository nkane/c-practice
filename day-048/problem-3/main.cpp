/*
 * Write a function named powfun() that raises an integer number passed to it to a 
 * postive integer power and displays the result. The positive integer should be the
 * second value passed to the function.
 *
 */

#include <stdio.h>

int 
PowFunI(int, int);

int
main()
{
	int x = 0, y = 0;

	printf("Enter in a base value:\n");
	scanf("%d", &x);

	printf("Enter in power value:\n");
	scanf("%d", &y);

	printf("%d to the power of %d = %d\n", x, y, PowFunI(x, y));

	return 0;
}

int 
PowFunI(int base, int power)
{
	int result = base;
	
	for (int i = 1; i < power; ++i)
	{
		result *= base;
	}

	return result;
}
