/*
 * Write a C function named IsValidReal() that checks for a valid double-percision
 * number. This kind of number can have an optional + or - sign, at most one decimal
 * point, which can also be the first character, and at least one digit between 0 
 * and 9 inclusive. The function should return an integer value of 1 if the entered
 * number is a real number, otherwise, it should return an integer value of 0.
 *
 */

#include <stdbool.h>
#include <stdio.h>

#define Size 40

bool
IsValidReal64(char string[]);

int
main()
{
	char value[Size]= { 0 };

	printf("Enter in real64 value: ");
	gets(value);

	if (IsValidReal64(value))
	{
		printf("Valid value: %s\n", value);
	}
	else
	{
		printf("Invalid value: %s\n", value);
	}

	return 0;
}

bool
IsValidReal64(char string[])
{
	bool result = true;
	int i = 0;
	int d = 0;

	// check for front positive or negative sign
	if (string[i] == '-' || string[i] == '+')
	{
		++i;
	}

	// check for decimal
	while (string[i] != '\0')
	{
		if (string[i] == '.')
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
			// value doesn't fall between 0 - 9
			if (string[i] < '0' || string[i] > '9')
			{
				result = false;
				break;
			}	
		}
		++i;
	}

	return result;
}

