/*
 * Write a C program that declares three one-dimensional arrays named price,
 * quantity, and amount. Each array should be capable of holding 10 elements.
 * Using a for loop, input values for the price and quantity arrays. The
 * entries in the amount array should be the product of the corresponding
 * values in the price and quantity arrays (thus, amount[i] = quantity[i] * price[i];).
 * After all of the data has been entered display the following output:
 *
 * 	Quantity Price Amount
 * 	-------- ----- ------
 *
 */

#include <stdio.h>

#define global_variable static

#define array_size(array)(sizeof(array)/sizeof(array[0]))

global_variable const int Size = 2;

global_variable int GlobalQuantity[Size];
global_variable float GlobalPrice[Size];
global_variable float GlobalAmount[Size];

int
main()
{
	
	for (int i = 0; i < array_size(GlobalQuantity); ++i)
	{
		printf("Enter in a price for item: ");
		scanf("%f", &GlobalPrice[i]);

		printf("Enter in a quantity of item: ");
		scanf("%d", &GlobalQuantity[i]);

		GlobalAmount[i] = ((float)GlobalQuantity[i] * GlobalPrice[i]);	
	}

	printf("Quantity\tPrice\tAmount\n");
	printf("--------\t-----\t------\n");
	for (int i = 0; i < array_size(GlobalQuantity); ++i)
	{
		printf("%d\t\t%.2f\t%.2f\n", GlobalQuantity[i], GlobalPrice[i], GlobalAmount[i]);
	}

	return 0;
}

