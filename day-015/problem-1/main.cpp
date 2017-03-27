/*
 * Write a C program that first displays the following prompt:
 * "Enter the temperature in degrees fahrenheit:"
 * 
 * Have your program accept a value entered from the keyboard and
 * convert the temperature entered to degrees Celsius, using the 
 * equation Celsius = (5.0 / 9.0) * (Fahrenheit - 32.0). Your
 * program should then display the temperature in degrees Celsius,
 * using an appropriate output message.
 */

#include <stdio.h>

struct Temperature
{
	float Fahrenheit;
	float Celsius;
};

inline float
RequestInput();

inline void 
PrettyPrint(Temperature *);

inline Temperature
CreateTemperature(float, float);

inline float
ComputeCelsiusFromFahrenheit(Temperature *);

int
main(void)
{
	Temperature T = CreateTemperature(RequestInput(), 0.0f);
	T.Celsius = ComputeCelsiusFromFahrenheit(&T);
	PrettyPrint(&T);

	return 0;
}
inline float
RequestInput()
{
	float value = 0.0f;
	printf("Enter the temperature in degrees fahrenheit:\n");
	scanf("%f", &value);
	return value;
}

inline void
PrettyPrint(Temperature *t)
{
	int result = 0;
	printf("Temperature F: %.2f\n", t->Fahrenheit);
	printf("Temperature C: %.2f\n", t->Celsius);
	scanf("%d", &result);
}

inline Temperature
CreateTemperature(float f, float c)
{
	return Temperature
	{
		f,
		c,
	};
}

inline float
ComputeCelsiusFromFahrenheit(Temperature *t)
{
	float result = (5.0f  / 9.0f) * (t->Fahrenheit - 32.0f);
	return result;
}
