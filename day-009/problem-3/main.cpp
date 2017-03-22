/*
 * Write a C program to convert temperature in degrees Fahrenheit to degrees
 * Celsius. The equation for this conversion is Celsius = 5.0 / 9.0 * (Fahrenheit - 32.0).
 * Have your program convert and display the Celsius temperature corresponding to 98.6
 * degrees Fahrenheit.
 */

#include <stdio.h>

struct Temperature
{
	float Celsius;
	float Fahrenheit;
};

inline void
Calculate_Celsius_Temperature(Temperature *);

int main(void)
{
	Temperature t = 
	{
		0.0f,
		98.6f,
	};

	Calculate_Celsius_Temperature(&t);

	printf("Temperature F: %.2f - C: %.2f", t.Fahrenheit, t.Celsius);

	return 0;
}

inline void
Calculate_Celsius_Temperature(Temperature * t)
{
	t->Celsius = ((5.0f / 9.0f) * (t->Fahrenheit - 32.0f));
}
