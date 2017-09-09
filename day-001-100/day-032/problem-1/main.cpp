/*
 * A machine purchased for $28,0000 is depreciated at a rate of $4,000 a year for seven years.
 * Write and run a C program that computes and displays a depreciation table for seven years.
 * The table should have the from:
 * 
 * YEAR 	DEPRECIATION		END-OF-YEAR VALUE		ACCUMULATED DEPRECIATION
 * ----		------------		-----------------		------------------------
 * 1		4000			24000				4000
 * 2		4000			20000				8000
 * 3		4000			16000				12000
 * 4		4000			12000				16000
 * 5		4000			8000				20000
 * 6		4000			4000				24000
 * 7		4000			0				28000
 * 
 */

#include <stdio.h>

#define global_variable static

global_variable const int Initial_Value = 28000;
global_variable const int Depreciation_Rate = 4000;
global_variable const int Years = 7;

struct Depreciation
{
	int InitialValue;
	int Rate;
	int CurrentValue;
	int Accumulated;
};

inline Depreciation
CreateDepreciation(int, int);

inline int
ComputeTotalDepreciation(Depreciation *);

inline void
PrettyPrint(Depreciation *, int);

int
main()
{
	Depreciation D = CreateDepreciation(Initial_Value, Depreciation_Rate);
	int i = 0;

	while (i < Years)
	{
		D.Accumulated = ComputeTotalDepreciation(&D);
		PrettyPrint(&D, (i + 1));
		++i;
	}

	return 0;
}


inline Depreciation
CreateDepreciation(int initialValue, int depreciationRate)
{
	Depreciation D = 
	{
		initialValue,
		depreciationRate,
		initialValue,
	};

	return D;
}

inline int
ComputeTotalDepreciation(Depreciation *d)
{
	int result = 0;
	d->CurrentValue -= d->Rate;
	result = d->InitialValue - d->CurrentValue;
	return result;
}

inline void
PrettyPrint(Depreciation *d, int year)
{
	printf("YEAR\tDEPRECIATION\tEND-OF-YEAR-VALUE\tACCUMULATED DEPRECIATION\n");
	printf("----\t------------\t-----------------\t------------------------\n");
	printf("%d\t %d\t\t %d\t\t\t\t %d\n", year, d->Rate, d->CurrentValue, d->Accumulated);
}

