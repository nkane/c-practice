/*
 * Write a C program that accepts a string of characters from a terminal and
 * displays the hexadecimal equivalent of each character.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Size = 256;

void
GetLine(char bufferString[], int size);

void
CharBufferToHex(char bufferString[], int size);

int
main()
{
	char StringBuffer[Size] = { 0 };

	printf("Enter in a string of text: \n");
	GetLine(StringBuffer, Size);

	CharBufferToHex(StringBuffer, Size);

	return 0;
}

void
GetLine(char bufferString[], int size)
{
	int i = 0;
	while (i < (size - 1) && (bufferString[i++] = getchar())!= '\n');
	bufferString[i] = '\0';
}

void
CharBufferToHex(char bufferString[], int size)
{
	for (int i = 0; i < size && bufferString[i] != '\0'; ++i)
	{
		if (bufferString[i] == '\n')
		{
			printf("Char: new line feed - Hex: 0x%x\n", bufferString[i], bufferString[i]);
		}
		else
		{
			printf("Char: %c - Hex: 0x%x\n", bufferString[i], bufferString[i]);
		}
	}
}

