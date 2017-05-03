/*
 * Write and run a C program that accepts six Fahrenheit temperatures, one at a time,
 * and converts each value entered to its Celsius equivalent before the next value is
 * requested. Use a for loop in your program. The conversion required is:
 *
 * Celsius = (5.0 / 9.0) * (Fahrenheit - 32.0)
 *
 */

#include <stdio.h>


#define global_variable static

global_variable int Total_Loop = 6;
global_variable float Compute_Value = (5.0f / 9.0f);
global_variable float Offset_Value = 32.0f;

struct Temperature
{
	float F;
	float C;
};

inline Temperature
CreateTemperature();

inline float
ComputeCelsiusT(Temperature *);

inline void
PrettyPrint(Temperature *);

int
main()
{
	Temperature T = CreateTemperature();


	for (int i = 0; i < Total_Loop; ++i)
	{
		printf("Enter in a valid fahrenheit temp: \n");
		scanf("%f", &T.F);
		T.C = ComputeCelsiusT(&T);
		PrettyPrint(&T);
	}

	return 0;
}


inline Temperature
CreateTemperature()
{
	Temperature T = {};
	return T;
}

inline float
ComputeCelsiusT(Temperature *t)
{
	float result = ((Compute_Value) * (t->F - Offset_Value));
	return result;
}

inline void 
PrettyPrint(Temperature *t)
{
	printf("F-Temp\t C-Temp\n");
	printf("%.2f\t%2.f\n", t->F, t->C);
}
