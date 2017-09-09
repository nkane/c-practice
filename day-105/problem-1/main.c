/*
 * Write a C program that accepts three user-entered numbers as one string. Once the string
 * has been accepted, have the program pass the string and the addresses of three single
 * precision variables to a function called separate(). The separate() function should extract
 * the three floating-point values from the passed string and store them using the passed variable
 * addresses.
 *
 */

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define Size 256
#define len(array)(sizeof(array)/sizeof(array[0]))

void
GetLine(char *stringBuffer, int max);

bool
Separate(char *stringBuffer, ...);

bool
IsValidRead32(char string[]);

int
main()
{
	char StringBuffer[Size] = { 0 };
	float x = 0.0f, y = 0.0f, z = 0.0f;

	printf("Enter in three numbers: ");
	GetLine(StringBuffer, len(StringBuffer));

	if (Separate(StringBuffer, &x, &y, &z))
	{
		printf("Valid separate: %f %f %f\n", x, y, z);
	}

	system("pause");

	return 0;
}

void
GetLine(char *stringBuffer, int max)
{
	int i = 0;
	while (i < max && (*(stringBuffer + i) = getchar()) != '\n')
	{
		++i;
	}
	*(stringBuffer + i) = ' ';
	*(stringBuffer + (i + 1)) = '\0';
}

bool
Separate(char *stringBuffer, ...)
{
	va_list args;
	va_start(args, stringBuffer);
	float *current = va_arg(args, float *);
	int i = 0;
	int j = 0;
	char tempBuffer[Size] = { 0 };
	bool result = true;
	while (current != NULL && *(stringBuffer + i) != '\0')
	{
		// next number
		if (*(stringBuffer + i) == ' ')
		{
			*(tempBuffer + j) = '\0';
			if (IsValidRead32(tempBuffer))
			{
				*current = strtof(tempBuffer,  NULL);
				current = va_arg(args, float *);
			}
			else
			{
				printf("Invalid valued passed: %s\n", tempBuffer);
				result = false;
				break;
			}
			j = 0;
		}
		else
		{
			// build float string
			*(tempBuffer + j) = *(stringBuffer + i);
			++j;
		}
		++i;
	}
	va_end(args);
	return result;
}

bool
IsValidRead32(char string[])
{
	bool result = true;
	int i = 0;
	int d = 0;
	// check for fron positive or negative sign
	if (*(string + i) == '-' || *(string + i) == '+')
	{
		++i;
	}
	// basic float validation
	while (*(string + i) != '\0')
	{
		if (*(string + i) == '.')
		{
			if (d > 0)
			{
				result = false;
				break;
			}
			++d;
		}
		else
		{
			if (*(string + i) < '0' || *(string + i) > '9')
			{
				result = false;
				break;
			}
		}
		++i;
	}
	return result;
}

