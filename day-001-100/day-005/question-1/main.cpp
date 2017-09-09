/*
 * Write, compile, and execute a C program to calculate the dollar amount contained
 * in a piggy bank. The bank currently contains 12 half-dollars, 20 quarters, 32 dimes,
 * 45 nickels, and 27 pennies.
 *
 * Then determine the following: no half-dollars, 17 quarters, 19 dimes, 10 nickels,
 * and 42 pennies.
 */

#include <stdio.h>

struct Amount
{
	int HalfDollars;
	int Quarters;
	int Dimes;
	int Nickels;
	int Pennies;
};

float CalculateDollarAmount(Amount *);

int main(void)
{
	Amount AmountOne = { 12, 20, 32, 45, 27 };

	float dollarAmount = CalculateDollarAmount(&AmountOne);

	printf("Piggy Bank One Contains: $%5.2f\n", dollarAmount);

	Amount AmountTwo = { 0, 17, 19, 10, 42 };

	dollarAmount = CalculateDollarAmount(&AmountTwo);

	printf("Piggy Bank Two Contains: $%5.2f\n", dollarAmount);

	return 0;
}

float CalculateDollarAmount(Amount *amount)
{
	float result = 0.0f;

	result += (amount->HalfDollars * 50.0f);
	result += (amount->Quarters * 25.0f);
	result += (amount->Dimes * 10.0f);
	result += (amount->Nickels * 5.0f);
	result += amount->Pennies;

	// result is in pennies at this point
	// 100 pennies = 1 dollars

	result /= 100.0f;

	return result;
}
