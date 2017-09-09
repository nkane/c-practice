/*
 * Write a C program to calculate the dollar amount contained
 * in a piggy bank. The bank currently contains 12 half-dollars,
 * 20 quarters, 32 dimes, 45 nickels, and 27 pennies.
 */

#include <stdio.h>


struct PiggyBank
{
	float Total;
	int HalfDollars;
	int Quarters;
	int Dimes;
	int Nickels;
	int Pennies;
};

inline float 
CalculatePiggyBankTotalF(PiggyBank *);

inline void
PrettyPrint(PiggyBank *);

int
main(void)
{
	PiggyBank Bank = 
	{
		0.0f,
		12,
		20,
		32,
		45,
		27,
	};

	Bank.Total = CalculatePiggyBankTotalF(&Bank);
	PrettyPrint(&Bank);

	return 0;
}

inline float 
CalculatePiggyBankTotalF(PiggyBank *p)
{
	float result = 0.0f;

	result += (50.0f * (float)p->HalfDollars);
	result += (25.0f * (float)p->Quarters);
	result += (10.0f * (float)p->Dimes);
	result += (5.0f * (float)p->Nickels);
	result += (float)p->Pennies;

	result /= 100;

	return result;
}

inline void
PrettyPrint(PiggyBank * p)
{
	printf("Half Dollars: %d\n", p->HalfDollars);
	printf("Quaters: %d\n", p->Quarters);
	printf("Dimes: %d\n", p->Dimes);
	printf("Nickels: %d\n", p->Nickels);
	printf("Pennies: %d\n", p->Pennies);

	printf("Total: %.2f\n", p->Total);
}
