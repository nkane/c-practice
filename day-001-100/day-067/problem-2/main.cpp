/*
 * Write a C function named change() that accepts a single-precision number
 * and the address of the integer variables named quarters, dimes, nickels,
 * and pennies. The function should determine the number of quarters, dimes,
 * nickels, and pennies passed to it and write these values directly into
 * the respective variables declared in its calling function.
 *
 */

#include <stdio.h>

void
Change(int, int *, int *, int*, int *);

int
main()
{
	float moneyValue = 0.0f;
	int quarters = 0, dimes = 0, nickels = 0, pennies = 0;

	printf("Enter in a single precision money value:\n");
	scanf("%f", &moneyValue);

	Change(((int)(moneyValue * 100.0f)), &quarters, &dimes, &nickels, &pennies);

	printf("Quarters: %d\n", quarters);
	printf("Dimes: %d\n", dimes);
	printf("Nickels: %d\n", nickels);
	printf("Pennies: %d\n", pennies);

	return 0;
}

void
Change(int value, int *q, int *d, int *n, int *p)
{
	while (value > 0)
	{
		if (value >= 25)
		{
			(*q) += 1;
			value -= 25;
		}
		else if (value >= 10)
		{
			(*d) += 1;
			value -= 10;
		}
		else if (value >= 5)
		{
			(*n) += 1;
			value -= 5;
		}
		else 
		{
			(*p) += 1;
			value -= 1;
		}
	}
}

