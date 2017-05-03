/*
 * Create a C program that displays a table of 20 temperature conversions from Fahrenheit
 * to Celsius. The table should start with a Fahrenheit value of 20 degrees and be incremented
 * in values of 4 degrees. Recall that Celsius = (5.0 / 9.0) * (Fahrenheit - 32.0).
 *
 */

#include <stdio.h>

#define global_variable static

global_variable float Display_Times = 20;
global_variable float Initi_Temp = 20.0f;
global_variable float Increment_Value = 4.0f;
global_variable float Compute_Static = (5.0f / 9.0f);
global_variable float F_Offset = 32.0f;

struct Temperature
{
	float F;
	float C;
};

inline Temperature
CreateTemperature(float);

inline float
ComputeCelsiusT(Temperature *);

inline void
PrettyPrint(Temperature *);

int
main()
{
	Temperature T = CreateTemperature(Initi_Temp);

	printf("F Temp\tC Temp\n");

	for (int i = 0; i < Display_Times; ++i)
	{
		PrettyPrint(&T);
		T.F += 4;
		T.C = ComputeCelsiusT(&T);
	}

	return 0;
}

inline Temperature
CreateTemperature(float f)
{
	Temperature T =
	{
		f,
		0.0f,
	};

	T.C = ComputeCelsiusT(&T);


	return T;
}

inline float
ComputeCelsiusT(Temperature *t)
{
	float result = ((Compute_Static) * (t->F - F_Offset));
	return result;
}

inline void
PrettyPrint(Temperature *t)
{
	printf("%.2f\t%.2f\n", t->F, t->C);
}

