/*
 * Write a C program that accepts a name as first name last name and then
 * display the name as last name, first name. For example, if the user
 * entered Gary Bronson, the output should be Bronson, Gary.
 *
 */

#include <stdio.h>
#include <stdbool.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

#define Size 256

void
GetLine(char *stringBuffer, int size);

int
GetStringLen(char *stringBuffer, int max);

void
ReverseName(char *stringBuffer, int size, int max);

void
Concatenate(char *stringOne, char *stringTwo);

void
ClearStringBuffer(char *string);

int
main()
{
	char StringBuffer[Size] = { 0 };

	printf("Enter a name (e.g., firstname lastname): ");

	GetLine(StringBuffer, len(StringBuffer));

	printf("Original Input: %s\n", StringBuffer);

	int actualLength = GetStringLen(StringBuffer, Size);

	ReverseName(StringBuffer, (actualLength - 1), Size);

	printf("Reversed: %s\n", StringBuffer);

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
GetStringLen(char *stringBuffer, int max)
{
	int i = 0;
	while (*(stringBuffer + i) != '\0' && i < max)
	{
		++i;
	}
	return i;
}

void
ReverseName(char *stringBuffer, int size, int max)
{
	char firstNameBuffer[50] = { 0 };
	char lastNameBuffer[50] = { 0 };
	bool space = false;

	for (int i = 0, j = 0; *(stringBuffer + i) != '\0'; ++i)
	{
		if (!space && *(stringBuffer + i) == ' ')
		{
			space = true;
			++i;
		}
		if (!space)
		{
			*(firstNameBuffer + i) = *(stringBuffer + i);
		}
		else
		{
			*(lastNameBuffer + j) = *(stringBuffer + i);
			++j;
		}
	}
	ClearStringBuffer(stringBuffer);
	Concatenate(stringBuffer, lastNameBuffer);
	Concatenate(stringBuffer, ", \0");
	Concatenate(stringBuffer, firstNameBuffer);
}

void
Concatenate(char *stringOne, char *stringTwo)
{
	// find the first index for string one
	int i = 0;
	while (*(stringOne + i) != '\0')
	{
		++i;
	}
	for (int j = 0; *(stringTwo + j) != '\0'; ++j)
	{
		*(stringOne + i++) = *(stringTwo + j);
	}
}

void
ClearStringBuffer(char *string)
{
	for (int i = 0; *(string + i) != '\0'; ++i)
	{
		*(string + i) = '\0';
	}
}

