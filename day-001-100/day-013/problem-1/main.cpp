/*
 * A model of world population, in billions of people, after 2000
 * is given by the equation Population = 6.0e^(02 (year - 2000))
 * 
 * Using this formula, write, compile, and execute a C program to estimate
 * the world population in the year 2010.
 */

#include <stdio.h>
#include <math.h>

inline int ComputePopulation(int);

int
main(void)
{
	printf("2010 Estimated Population (in billions): %d\n", ComputePopulation(2010));
	return 0;
}

inline int ComputePopulation(int year)
{
	float result = ((float)year - 2000.0f);
	result *= 0.02f;
	result = pow((6.0f * 2.0f), result);
	return (int)result;
}
