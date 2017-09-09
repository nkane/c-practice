/*
 * The number of bacteria, B, in a certain culture that is
 * subject to refrigeration can be approximated by the equation
 * B = 300,000 * e^(-.032t), where t is the time, in hours, that
 * culture has been refrigerated. Using this equation, write, 
 * compile, and execute a single C program that calculates
 * the number of bacteria in the culture after it has been in
 * the refrigerator for 8 hours, and display the result.
 * e is the constant 2.72
 */

#include <stdio.h>
#include <math.h>

#define E_CONST 2.72f

struct BacteriaCulture
{
	float GrowthRate;
	float Time;
};

inline BacteriaCulture
MakeBacteriaCulture(float, float);

inline float
ComputeTotalBacteria(BacteriaCulture *);

inline void
PrettyPrint(BacteriaCulture *, float);

int
main(void)
{
	BacteriaCulture B = MakeBacteriaCulture(300000.0f, 8.0f);
	float totalB = (B.GrowthRate + ComputeTotalBacteria(&B));
	PrettyPrint(&B, totalB);

	return 0;
}

inline BacteriaCulture
MakeBacteriaCulture(float growthRate, float time)
{
	return BacteriaCulture
	{
		growthRate,
		time,
	};
}

inline float
ComputeTotalBacteria(BacteriaCulture *b)
{
	float result = pow(E_CONST, (-0.032f * b->Time));
	result *= b->GrowthRate;
	return result;
}

inline void
PrettyPrint(BacteriaCulture * b, float totalB)
{
	printf("Bacteria Growth Rate: %.2f\n", b->GrowthRate);
	printf("Bacteria Time in Fridge: %.2f\n", b->Time);
	printf("Bacteria Total After: %.2f\n", totalB);
}
