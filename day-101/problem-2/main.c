/*
 * Include the string library functions strlen(), strcat(), and strncat() within a
 * function having the prototype void concat(char string[], char string2[], int maxlength).
 * The concat() function should perform a complete concatenation of string2 to string1
 * only if the length of the concatenated string does not exceed maxlength, which is the
 * maximum length defined for string1. If the concatenated string exceeds maxlength, 
 * concatenate only the characters in string2, so that the maximum combined string length
 * is equal to maxlength - 1, which provides enough room for the end-of-string NULL
 * characters.
 *
 */

#include <stdio.h>
#include <string.h>

#define Size 20

void
GetLine(char *stringBuffer, int size);

void
Concat(char string1[], char string2[], int maxLength);

int
main()
{
	char StringBuffer1[Size] = { 0 };
	char StringBuffer2[Size] = { 0 };

	printf("Enter in a string:\n");
	GetLine(StringBuffer1, Size);

	printf("Enter in a string:\n");
	GetLine(StringBuffer2, Size);

	printf("String1: %s\n", StringBuffer1);
	printf("String2: %s\n", StringBuffer2);

	Concat(StringBuffer1, StringBuffer2, Size);

	printf("Concatenated String: %s\n", StringBuffer1);

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

void
Concat(char string1[], char string2[], int maxLength)
{
	int string1Length = strlen(string1);
	int string2Length = strlen(string2);
	if ((string1Length + string2Length) <= (maxLength - 2))
	{
		strcat(string1, " ");
		strcat(string1, string2);
	}
	else 
	{
		int max = ((maxLength - 2) - string1Length);
		strcat(string1, " ");
		strncat(string1, string2, max);
	}
}

