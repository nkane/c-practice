/*
 * Write a C function named toUpper() that converts individual lowcase letters into
 * uppercase letters. The expression ch - 'a' + 'A' can be used to make the conversion
 * for any lowercase character stored in ch.
 *
 * Add a data input check to the function written above to verify that a valid lowercase
 * letter is passed to the function. A character is lowercase if it is greater than or equal
 * to a and less than or equal to z. If the character is not a valid lowercase letter, have
 * the function toUpper() return the passed character unaltered.
 *
 * Write a C program that accepts a string from a terminal and converts all lowercase letters
 * in the string to uppercase leters.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Size = 256;

void
GetLine(char stringBuffer[], int size);

char
charToUpper(char c);

void
stringToUpper(char stringBuffer[], int size);

int
main()
{
	char StringBuffer[Size] = { 0 };

	printf("Enter in a string:\n");
	GetLine(StringBuffer, Size);

	printf("\nTesting first element in string ...\n");
	printf("original value: %c\n", StringBuffer[0]);
	printf("uppper value:   %c\n\n", charToUpper(StringBuffer[0]));

	printf("\nTesting string ...\n");
	printf("original value: %s\n", StringBuffer);
	stringToUpper(StringBuffer, Size);
	printf("uppper value:   %s\n\n", StringBuffer);

	return 0;
}

void
GetLine(char stringBuffer[], int size)
{
	int i = 0;
	while ((i < (size -1)) && ((stringBuffer[i++] = getchar()) != '\n'));
	stringBuffer[i] = '\0';
}

char
charToUpper(char c)
{
	char low = 'a';
	char high = 'z';
	if (c >= low && c <= high)
	{
		c = (c - low) + 'A';
	}
	return c;
}

void
stringToUpper(char stringBuffer[], int size)
{
	for (int i = 0; i < size && stringBuffer[i] != '\0'; ++i)
	{
		stringBuffer[i] = charToUpper(stringBuffer[i]);
	}
}

