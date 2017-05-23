/*
 * Write a function named totamt() that accepts four integer arguments named
 * quarters, dimes, nickels, and pennies, which represent the number of 
 * quarters, dimes, nickels, and pennies in a piggybank. The function should determine
 * and return the dollar value of the number of quarters, dimes, nickels, and pennies
 * passed to it.
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct PiggyBank
{
	int Q;
	int D;
	int N;
	int P;
	float DollarValue;
};

inline PiggyBank *
CreatePiggyBank();

inline float
ComputeDollarValue(PiggyBank *);

inline void
DestoryPiggyBank(PiggyBank *);

int
main()
{
	PiggyBank * PB = CreatePiggyBank();

	printf("Piggy bank contains: $%.2f\n", PB->DollarValue);

	DestoryPiggyBank(PB);

	return 0;
}

inline PiggyBank *
CreatePiggyBank()
{
	PiggyBank * PB = (PiggyBank *)malloc(sizeof(PiggyBank));

	printf("Enter in quarters: ");
	scanf("%d", &PB->Q);

	printf("Enter in dimes: ");
	scanf("%d", &PB->D);

	printf("Enter in nickels: ");
	scanf("%d", &PB->N);

	printf("Enter in pennies: ");
	scanf("%d", &PB->P);

	PB->DollarValue = ComputeDollarValue(PB);

	return PB;
}

inline float
ComputeDollarValue(PiggyBank *pb)
{
	float result = 0.0f;
	result += (pb->Q * 0.25f);
	result += (pb->D * 0.10f);
	result += (pb->N * 0.05f);
	result += (pb->P * 0.01f);
	return result;
}

inline void
DestoryPiggyBank(PiggyBank *pb)
{
	if (pb)
	{
		free(pb);
	}
}

