/*
 * Write a C program that accepts a number followed by one space and then a letter.
 * If the letter following the number is f, the program is to treat the number as a
 * temperature in degrees Fahrenheiet, convert the number to the equivalent degrees
 * Celsius, and print a suitable display message. If the letter following the number
 * is c, the program is to treat the number entered as a temperature in Celsius,
 * convert the number to the equivalente degrees Fahrenheit, and print a suitable
 * display message. If the letter is neither f nor c, the program should print a
 * message indicating that the data entered is incorrect and terminate. Use and if-
 * else chain in your program and make use of the conversion formulas:
 *
 * Celsius = (5.0 / 9.0) * (Fahrenheit - 32.0)
 * Fahrenheit = (9.0 / 5.0) * Celsius + 32.0
 * 
 */

#include <stdio.h>
#include <ctype.h>

struct Input
{
	float temperature;
	float convertedTemperature;
	char scale;
};

inline Input
CreateInput();

inline float
ConvertTemperature(Input *);

inline void
PrettyPrint(Input *);

int
main()
{
	Input I = CreateInput();
	PrettyPrint(&I);

	return 0;
}

inline Input
CreateInput()
{
	Input I = {};
	printf("Enter in a temperature and scale (e.g., 30 c):\n");
	scanf("%f %c", &I.temperature, &I.scale);
	I.scale = toupper(I.scale);

	I.convertedTemperature = ConvertTemperature(&I);

	return I;
}

inline float
ConvertTemperature(Input *i)
{
	float result;

	if (i->scale == 'C')
	{
		result = ((9.0f / 5.0f) * (i->temperature + 32.0f));
	}
	else if (i->scale == 'F')
	{
		result = ((5.0f / 9.0f) * (i->temperature - 32.0f));
	}

	return result;
}

inline void
PrettyPrint(Input *i)
{
	printf("Input Temperature: %.2f %c\n", i->temperature, i->scale);
	printf("Converted Temperature: %.2f %c\n", i->convertedTemperature, (i->scale == 'F' ? 'C' : 'F'));
}
