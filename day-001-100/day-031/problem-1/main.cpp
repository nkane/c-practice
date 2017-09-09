/*
 * Write a C program that produces a table that prints out Fahrenheit
 * and Celsius temperatures starting at -10 Celsius and ends with
 * 60 Celsius in increments of 10.
 * 
 * F = C * (9 / 5) + 32
 * C = (F - 32) * 9 / 5
 */

#include <stdio.h>

#define global_variable static

global_variable float Start_Point = -10.0f;
global_variable float End_Point = 60.0f;
global_variable float Increment_Value = 10.0f;

struct Temperature
{
	float F;
	float C;
};

inline Temperature
CreateTemperature(float);

inline float
ComputeFahrenheit(Temperature *);

inline void
PrettyPrint(Temperature *);

int
main()
{
	Temperature T;

	for (float i = Start_Point; i < End_Point; (i = i + Increment_Value))
	{
		T = CreateTemperature(i);
		PrettyPrint(&T);
	}

	return 0;
}

inline Temperature
CreateTemperature(float celsius)
{
	Temperature T =
	{
		0.0f,
		celsius,
	};

	T.F = ComputeFahrenheit(&T);

	return T;
}

inline float
ComputeFahrenheit(Temperature *t)
{
	float result = 0.0f;
	result = ((t->C * (9.0f / 5.0f)) + 32.0f);
	return result;
}

inline void
PrettyPrint(Temperature *t)
{
	printf("Celsius: %.2f\tFahrenheit: %.2f\n", t->C, t->F);
}
