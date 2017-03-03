/*
 * Make a program that converts 86.5 degrees Fahrenheit into
 * its equivalent Celsius value
 */

#include <stdio.h>

inline float CalculateCelsiusFromFahrenheit(float);

int main(void)
{
	float celsius;
	float fahrenheit = 86.5f;

	celsius = CalculateCelsiusFromFahrenheit(fahrenheit);

	printf("The Celsius equivalent of %5.2f degrees Fahrenheit\n", fahrenheit);
	printf("       is %5.2f degres\n", celsius);

	return 0;
}

inline float CalculateCelsiusFromFahrenheit(float fahrenheit)
{
	float result = (5.0f / 9.0f * (fahrenheit - 32.0f));
	return result;
}
