/*
 * Given a program, use #define statements where for appropriate literals
 * Example Program: 
 * 
 * ...
 * float fahren, celsius;
 * printf("Enter a temperature in degrees Fahrenheit:\n");
 * scanf("%f", &fahren);
 * celsius = (5.0f / 9.0) * (fahren - 32.0f);
 * printf("The equivalent Celsius temperature is %f\n, celsius);
 * return 0;
 * ..
 */

#include <stdio.h>

#define calculate_celsius(f) ((5.0f / 9.0f) * (f - 32.0f))

struct Temperature
{
	float Fahrenheit;
	float Celsius;
};

inline Temperature
CreateTemperature();

inline void
ComputeCelsius(Temperature *);

int
main(void)
{
	Temperature T = CreateTemperature();
	ComputeCelsius(&T);

	return 0;
}

inline Temperature
CreateTemperature()
{
	Temperature T = {};
	printf("Enter a temperature in degrees Fahrenheit:\n");
	scanf("%f", &T.Fahrenheit);
	return T;
}

inline void
ComputeCelsius(Temperature *t)
{
	t->Celsius = calculate_celsius(t->Fahrenheit);
	printf("The equivalent Celsius temperature is %f\n", t->Celsius);
}
