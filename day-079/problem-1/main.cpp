/*
 * Write a C program that stores the following prices in a global
 * array:
 * 	- 9.92, 6.32, 12.63, 5.95, 10.29
 *
 * Your program should also create two automatic arrays named units
 * and amounts, each capable of storing five double-percision numbers.
 * Using a for loop and a scanf() function call, have the program
 * accept five user-input numbers into the units array when the program
 * is run. The program should store the product of the corresponding values
 * in the prices and units array in the amounts array (for example,
 * amounts[i] = price[i] * units[i]) and display the following output:
 *
 * Price	Units		Amount
 * -----	----		------
 * 9.92		  *		   *
 * ...		....		......
 *
 * Total: 			......
 */

#include <stdio.h>

#define array_size(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 5;

global_variable double Prices[Size] = { 9.92, 6.32, 12.63, 5.95, 10.29, };

int
main()
{
	double Amounts[Size] = { 0 };
	int Units[Size] = { 0 };
	double total = 0;

	for (int i = 0; i < array_size(Units); ++i)
	{
		printf("Enter in units for [%d]: ", i);
		scanf("%d", &Units[i]);
		Amounts[i] = (Prices[i] * Units[i]);
		total += Amounts[i];
	}

	printf("\nPrices\t\tUnits\t\tAmount\n");
	printf("------\t\t-----\t\t------\n");
	for (int i = 0; i < array_size(Prices); ++i)
	{
		printf("%.2lf\t\t%d\t\t%.2lf\n", Prices[i], Units[i], Amounts[i]);
	}

	printf("\nTotal: %.2lf\n", total);

	return 0;
}

