/*
 * Write a function to count the number of lines entered. (Hint: you will not be able to
 * use gets() to input the lines because gets() ends input on receipt of the first newline
 * character.)
 *
 */

#include <stdio.h>

#define Size 1000

void
GetString(char *stringBuffer, int max);

int
CountNewLines(char *stringBuffer, int max);

int
main()
{
	char StringBuffer[Size] = { 0 };

	printf("Enter a string of text (EOF ends read):\n");
	GetString(StringBuffer, Size);
	printf("Line Count: %d\n", CountNewLines(StringBuffer, Size));

	return 0;
}

void
GetString(char *stringBuffer, int max)
{
	int i = 0;
	while (i < (max - 1) && (*(stringBuffer + i) = getchar()) != EOF)
	{
		++i;
	}
	*(stringBuffer + i) = '\0';
}

int
CountNewLines(char *stringBuffer, int max)
{
	int i = 0;
	int count = 0;
	while (i < (max - 1) && *(stringBuffer + i) != '\0')
	{
		if (*(stringBuffer + i) == '\n')
		{
			++count;
		}
		++i;
	}
	return count;
}

