/*
 * Modify the previous program in problem-2 to request the starting Celsius value, 
 * the ending Celsius value, and the increment. Thus, instead of the condition checking
 * for a fixed count, the condition checks for the ending Celsius value.
 */

#include <stdio.h>

#define global_variable static

global_variable const float Conversion_Value = (9.0f / 5.0f);

struct Temperature
{
	float CCurrent;
	float CEnd;
	float F;
};

inline Temperature
CreateTemperature();

inline float
ComputeFahrenheitT(Temperature *);

inline void
PrettyPrint(Temperature *);

int
main()
{
	Temperature T = CreateTemperature();

	float incrementValue = 0.0f;
	printf("Enter in the increment value:\n");
	scanf("%f", &incrementValue);

	PrettyPrint(&T);

	while (T.CCurrent != T.CEnd)
	{
		T.CCurrent += incrementValue;
		T.F = ComputeFahrenheitT(&T);
		PrettyPrint(&T);
	}

	return 0;
}

inline Temperature
CreateTemperature()
{
	Temperature T = {};

	printf("Enter in the starting Celsius:\n");
	scanf("%f", &T.CCurrent);

	printf("Enter in the ending Celsius:\n");
	scanf("%f", &T.CEnd);

	T.F = ComputeFahrenheitT(&T);

	return T;
}

inline float
ComputeFahrenheitT(Temperature *t)
{
	float result = 0.0f;
	result = ((Conversion_Value * t->CCurrent) + 32.0f);
	return result;
}

inline void
PrettyPrint(Temperature *t)
{
	printf("Celsius: %.2f\tFahrenheit: %.2f\n", t->CCurrent, t->F);
}

