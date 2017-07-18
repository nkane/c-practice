/*
 * Write a program that declares three one-dimensional arrays named price,
 * quantity, and amount. Each array should be delcared in main() and should
 * be capable of holding 10 double-percision numbers. The numbers that should
 * be stored in price are:
 *
 * 	- 10.62, 14.89, 16.55, 18.62, 9.47, 6.58, 18.32, 12.15, 3.98
 *
 * The numbers that should be stored in quantity are:
 *
 * 	- 4, 8.5, 6, 8.35, 9, 15.3, 3, 5.4, 2.9, 4.8
 *
 * Your program should pass these three arrays to a function called extend(),
 * which should calculate the elements in the amount array as the product
 * of the equivalent elements in the price and quantity arrays (for example, 
 * amount[1] = price[1] * quantity[1]). After extend() has put values into the
 * amount array, the values in the array should be displayed from within main.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 10;

void
Extend(double price[], double quantity[], double amount[], int size);

void
PrintArray(double price[], double quantity[], double amount[], int size);

int
main()
{
	double price[Size] = { 10.62, 14.89, 16.55, 18.62, 9.47, 6.58, 18.32, 12.15, 3.98, };
	double quantity[Size]  = { 4.0, 8.5, 6, 8.35, 9, 15.3, 3, 5.4, 2.9, 4.8, };
	double amount[Size] = { 0.0 };

	Extend(price, quantity, amount, len(price));
	PrintArray(price, quantity, amount, len(price));

	return 0;
}

void
Extend(double price[], double quantity[], double amount[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		amount[i] = (price[i] * quantity[i]);
	}
}

void
PrintArray(double price[], double quantity[], double amount[], int size)
{
	printf("Price\tQuantity\tAmount\n");
	printf("-----\t--------\t------\n");
	for (int i = 0; i < size; ++i)
	{
		printf("%.2lf\t%.2lf\t\t%.2lf\n", price[i], quantity[i], amount[i]);
	}
}

