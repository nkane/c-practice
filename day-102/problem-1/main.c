/*
 * Enter and execute program 9.8 five times. The first time you run the program,
 * enter a valid integer number, the second time enter a double-percision number,
 * and the third time enter a character. Next enter the value 12e34 and then 31234.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Size 40

bool
isValidInt(char stringBuffer[]);

int
main()
{
	char StringBuffer[Size] = { 0 };
	int number;

	printf("Enter an integer: ");
	gets(StringBuffer);

	if (isValidInt(StringBuffer) == true)
	{
		number = atoi(StringBuffer);
		printf("The number you have entered is %d\n", number);
	}
	else
	{
		printf("The number you entered is not a valid integer.\n");
	}

	return 0;
}

bool
isValidInt(char stringBuffer[])
{
	int start = 0;
	int i;
	int sign = false;

	if (stringBuffer[0] == '\0')
	{
		return false;
	}
	
	if (stringBuffer[0] == '-' || stringBuffer[0] == '+')
	{
		sign = true;
		start = 1;
	}

	if (sign && stringBuffer[1] == '\0')
	{
		return false;
	}

	i = start;
	while (stringBuffer[i] != '\0')
	{
		if (stringBuffer[i] < '0' || stringBuffer[i] > '9')
		{
			return false;
		}
		++i;
	}

	return true;
}

