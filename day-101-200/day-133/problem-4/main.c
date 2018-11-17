/*
 * Write a C program that delcares three single-dimensional arrays named
 * price, quantity, and amount. Each array should be declared in main() and
 * be capable of holding 10 double-percision numbers. The numbers to be stored in
 * price are 10.62, 14.89, 13.21, 16.55, 19.62, 9.47, 6.58, 19.32, 12.15, 3.99.
 * The numbers to be stored in quantity are 4, 9.5, 6, 7.35, 9, 15.3, 3, 5.4, 2.9,
 * 4.9. Have your program pass these arrays to a function called extend(), which
 * calculates the elements in the amount array as the product of the equivalent
 * elements in the price and quantity arrays (for example, amount[1] = price[1] *
 * quantity[1]). After extend() has put values into the amount array, display the
 * values in the array from within main(). Write the extend() function using 
 * pointers.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

void
Extend(double *price, double *quantity, double *amount, int size);

void
Display(double *amount, int size);

int
main()
{
	double price[10] = { 10.62, 14.89, 13.21, 16.55, 19.62, 9.47, 6.58, 19.32, 12.15, 3.99, };
	double quantity[10] = { 4.0, 9.5, 6.0, 7.35, 9.0, 15.3, 3.0, 5.4, 2.9, 4.9, };
	double amount[10] = { 0.0 };

	Extend(price, quantity, amount, len(price));
	Display(amount, len(amount));

	return 0;
}

void
Extend(double *price, double *quantity, double *amount, int size)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		*(amount + i) = (*(price + i)) * (*(quantity + i));
	}
}

void
Display(double *amount, int size)
{
	int i;
	printf("Amounts: ");
	for (i = 0; i < size; ++i)
	{
		printf(" %6.2lf, ", *(amount + i));
	}
}

