/*
 * Write a function named countlets() that returns the number of letters in an
 * entered string. Digits, spaces, punctuation, tabs, and newline characters
 * should not be included in the returned count.
 *
 */

#include <stdio.h>

#define Size 256

void
GetLine(char *stringBuffer, int size);

int
CountLetters(char *stringBuffer);

int
main()
{
	char StringBuffer[Size] = { 0 };

	printf("Enter in a string:\n");

	GetLine(StringBuffer, Size);

	printf("String: %s\n", StringBuffer);
	printf("Letter Count: %d\n", CountLetters(StringBuffer));

	return 0;
}

void
GetLine(char *stringBuffer, int size)
{
	int i = 0;
	while (i < (size - 1) && (*(stringBuffer + i) = getchar()) != '\n')
	{
		++i;
	}
	*(stringBuffer + i) = '\0';
}

int
CountLetters(char *stringBuffer)
{
	int count = 0;
	char c; 
	for (int i = 0; *(stringBuffer + i) != '\0'; ++i)
	{
		c = (*(stringBuffer + i));
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			++count;
		}
	}
	return count;
}

