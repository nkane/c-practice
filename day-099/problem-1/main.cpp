/*
 * Write a C program that accepts a string from a terminal and converts
 * all uppercase letters in the string to lowercase letters.
 *
 */

#include <stdio.h>

#define global_variable static
#define len(array)(sizeof(array)/sizeof(array[0]))

global_variable const int Size = 256;

void
GetLine(char *stringBuffer, int size);

void
StringToLower(char *stringBuffer, int size);

int
main()
{
	char StringBuffer[Size] = { 0 };

	printf("Enter in a string:\n");
	GetLine(StringBuffer, len(StringBuffer));
	StringToLower(StringBuffer, len(StringBuffer));
	printf("%s", StringBuffer);

	return 0;
}

void
GetLine(char *stringBuffer, int size)
{
	int i = 0;
	while (i < (size - 1) && (*(stringBuffer + i++) = getchar()) != '\n');
	*(stringBuffer + i) = '\0';
}



void
StringToLower(char *stringBuffer, int size)
{
	char c;
	for (int i = 0; i < size && *(stringBuffer + i) != '\0'; ++i)
	{
		// character is within uppercase range
		c = *(stringBuffer + i);
		if(c >= 'A' && c <= 'Z')
		{
			*(stringBuffer + i) = c - 'A' + 'a';
		}
	}
}

