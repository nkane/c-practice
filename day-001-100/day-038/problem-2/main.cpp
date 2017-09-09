/*
 * A machine purchased for $28,000 is depreciated at a rate of $4,000 a year for seven years.
 * Write and run a program that computes and displays a depreciation table for seven years.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const float Initial_Value = 28000.0f;
global_variable const float Depreciation_Rate = 4000.0f;
global_variable const int Years = 7;

struct Item
{
	float InitialValue;
	float CurrentValue;
	float DepreciationRate;
};

inline Item
CreateItem(float, float);

inline float
ComputeCurrentValueI(Item *);

inline void
PrettyPrintI(Item *, int);

int
main()
{
	Item I = CreateItem(Initial_Value, Depreciation_Rate);
	printf("Year\tDepreciation\tEOY Value\tAccumulated Depreciation\n");
	PrettyPrintI(&I, 0);

	for (int i = 0; i < Years; ++i)
	{
		I.CurrentValue = ComputeCurrentValueI(&I);
		PrettyPrintI(&I, (i + 1));
	}

	return 0;
}

inline Item
CreateItem(float initialAmount, float depreciationRate)
{
	Item I = 
	{
		initialAmount,
		initialAmount,
		depreciationRate,
	};

	return I;
}

inline float
ComputeCurrentValueI(Item *i)
{
	float result = (i->CurrentValue - i->DepreciationRate);
	return result;
}

inline void
PrettyPrintI(Item *i, int year)
{
	printf("%d\t    %.2f\t%.2f\t\t%.2f\n",
	        year,
		i->DepreciationRate,
		i->CurrentValue, 
		(i->InitialValue - i->CurrentValue));
}


