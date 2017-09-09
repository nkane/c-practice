/*
 * Write a function named gallonsToLiters() that converts gallons of liquid to liters
 * using the relationship that there are 3.7854 liters to the gallon
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define global_variable static

global_variable const float Liters_To_Gallons = 3.7854f;

struct Liquid
{
	float G;
	float L;
};

inline Liquid *
CreateLiquid(float);

inline float
ComputeGallonsL(float);

inline void
DestoryLiquid(Liquid *);

int
main()
{
	float l = 0.0f;

	printf("Enter in a liter value:\n");
	scanf("%f", &l);
	Liquid * L = CreateLiquid(l);

	printf("Liters %.2f -> Gallon: %.2f\n", L->L, L->G);

	return 0;
}

inline Liquid *
CreateLiquid(float l)
{
	Liquid * L = (Liquid *)malloc(sizeof(Liquid));
	L->L = l;
	L->G = ComputeGallonsL(L->L);;
	return L;
}

inline float
ComputeGallonsL(float l)
{
	return (l * Liters_To_Gallons);
}

inline void
DestoryLiquid(Liquid *l)
{
	if (l)
	{
		free(l);
	}
}

