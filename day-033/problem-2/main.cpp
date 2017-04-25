/*
 * Write a C program to convert Celsius degrees to Fahrenheit. The program should request
 * the starting Celsius value, the number of conversions to be made, and the increment
 * between Celsius values. The display should have appropriate headings and list the 
 * Celsius value and the corresponding Fahrenheit value. Use the relationship:
 * Fahrenheit = (9.0 / 5.0) * Celsius + 32.0
 */

#include <stdio.h>


#define global_variable static

global_variable const float Conversion_Value = (9.0f / 5.0f);

struct Temperature
{
	float C;
	float F;
};

struct UserInput
{
	int Conversions;
	float IncrementValue;
};

inline Temperature
CreateTemperature();

inline float
ComputeFahnrehheitT(Temperature *);

inline void
PrettyPrint(Temperature *, int);

inline UserInput
CreateUserInput();

int
main()
{
	Temperature T = CreateTemperature();
	UserInput UI = CreateUserInput();
	int i = 0;

	do {
		PrettyPrint(&T, (i + 1));
		
		T.C += UI.IncrementValue;
		T.F = ComputeFahnrehheitT(&T);

		++i;
	} while(i < UI.Conversions);

	PrettyPrint(&T, (i + 1));

	return 0;
}
inline Temperature
CreateTemperature()
{
	Temperature T = {};
	
	printf("Enter in the starting Celsius:\n");
	scanf("%f", &T.C);

	T.F = ComputeFahnrehheitT(&T);

	return T;
}


inline float
ComputeFahnrehheitT(Temperature *t)
{
	float result = 0.0f;
	result = ((Conversion_Value * t->C) + 32.0f);
	return result;
}

inline UserInput
CreateUserInput()
{
	UserInput UI = {};

	printf("Enter in the number of conversion:\n");
	scanf("%d", &UI.Conversions);

	printf("Enter increment value:\n");
	scanf("%f", &UI.IncrementValue);

	return UI;
}

inline void
PrettyPrint(Temperature *t, int currentIncrement)
{
	printf("%d | Celsius: %.2f\tFahrenheit: %.2f\n", currentIncrement, t->C, t->F);
}
