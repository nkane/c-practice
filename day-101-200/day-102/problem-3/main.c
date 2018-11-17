/*
 * Write a function that checks each digit as it is entered, rather than checking
 * the complete string, as done in program 9.8
 *
 */

#include <stdio.h>
#include <stdbool.h>

#define Size 256

bool
GetLine(char stringBuffer[], int size);

bool
IsValidInt(char c);

int
main()
{
	char StringBuffer[Size] = { 0 };
	int number = 0;

	printf("Enter an integer: ");
	if (!GetLine(StringBuffer, Size))
	{
		printf("Invalid int entered: %s\n", StringBuffer);
	}
	else
	{
		number = atoi(StringBuffer);
		printf("The number you have entered is %d\n", number);
	}

	return 0;
}

bool
GetLine(char stringBuffer[], int size)
{
	int i = 0;
	while (i < (size - 1) && (stringBuffer[i] = getchar()) != '\n')
	{
		if (IsValidInt(stringBuffer[i]) == false)
		{
			return false;
		}
		++i;
	}
	return true;
}

bool
IsValidInt(char c)
{
	bool result = true;
	if (c < '0' || c > '9')
	{
		result = false;
	}
	return result;
}

