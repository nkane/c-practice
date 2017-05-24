/*
 * Write the function tempConvert() to accept a temperature and a 
 * character argument. If the character passed to the function is the letter f, 
 * the function should convert the passed temperature from Fahrenheit to Celsius, else
 * the function should convert the passed temperature from Celsius to Fahrenheit.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Temperature
{
	float F;
	float C;
	bool IsValid;
};

inline Temperature * 
CreateTemperature(float, char);

inline void
DestroryTemperature(Temperature *);

inline float
ComputeFTemperature(float);

inline float
ComputeCTemperature(float);

int
main()
{
	char type;
	printf("Enter in temperature type (F or C):\n");
	scanf("\n%c", &type);
	type = toupper(type);


	float temp;
	printf("Enter the temperature value:\n");
	scanf("%f", &temp);

	Temperature * T = CreateTemperature(temp, type);

	if (T->IsValid)
	{
		printf("Celsius: %.2f\n", T->C);
		printf("Fahrenheit: %.2f\n", T->F);
	}
	else
	{
		printf("ERROR - Invalid temperature type submited!\n");
	}

	DestroryTemperature(T);

	return 0;
}

inline Temperature * 
CreateTemperature(float temp, char type)
{
	Temperature * T = (Temperature *)malloc(sizeof(Temperature));
	T->F = 0.0f;
	T->C = 0.0f;
	T->IsValid = true;

	switch (type)
	{
		case 'C': 
		{
			T->C = temp;
			T->F = ComputeFTemperature(T->C);
		} break;

		case 'F': 
		{
			T->F = temp;
			T->C = ComputeCTemperature(T->F);
		} break;

		default:
		{
			T->IsValid = false;
		} break;
	}
	
	return T;
}

inline void
DestroryTemperature(Temperature * t)
{
	if (t)
	{
		free(t);
	}
}

inline float
ComputeFTemperature(float c)
{
	float result = 0.0f;
	result = (c * (9.0f / 5.0f) + 32.0f);
	return result;
}

inline float
ComputeCTemperature(float f)
{
	float result = 0.0f;
	result = ((f - 32.0f) * (9.0f / 5.0f));
	return result;
}

