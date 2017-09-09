/*
 * Write a program to calculate the distance, in feet, of a trip that is
 * 2.36 miles long. One mile is equal to 5,280 feet.
 */

#include <stdio.h>

#define MPF 5280

struct Trip
{
	float Miles;
	float Feet;
};

inline float
CalculateFeetFromMilesF(float miles);

inline void
PrettyPrint(Trip *);

int
main(void)
{
	Trip T = { 2.36f, 0.0f };

	T.Feet = CalculateFeetFromMilesF(T.Miles);

	PrettyPrint(&T);
	
	return 0;
}

inline float
CalculateFeetFromMilesF(float miles)
{
	float result = (miles * MPF);
	return result;
}

inline void
PrettyPrint(Trip * t)
{
	printf("Trip Miles: %.2f\n", t->Miles);
	printf("Trip Feet: %.2f\n", t->Feet);
}
