/*
 * Write a C program that accepts a string of characters from a terminal
 * and displays the string one word per line.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Size = 256;

void
GetLine(char bufferString[], int size);

void
ReadEachLine(char bufferString[], int size);

int
main()
{
	char BufferString[Size] = { 0 };

	printf("Enter in a text string:\n");
	GetLine(BufferString, Size);
	ReadEachLine(BufferString, Size);

	return 0;
}

void
GetLine(char bufferString[], int size)
{
	int i = 0;
	while (i < (size - 1) && (bufferString[i++] = getchar()) != '\n');
	bufferString[i] = '\0';
}

void
ReadEachLine(char bufferString[], int size)
{
	char tempBuffer[Size] = { 0 };
	for (int i = 0; i < size && bufferString != '\0'; ++i)
	{
		if (bufferString[i] == ' ')
		{
			tempBuffer[i] = '\n';
		}
		else if (bufferString[i] == '\n')
		{
			tempBuffer[i] = ' ';
		}
		else
		{
			tempBuffer[i] = bufferString[i];
		}
	}
	printf("%s", tempBuffer);
}

