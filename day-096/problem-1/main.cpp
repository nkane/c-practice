/*
 * Write a C function to count the total number of characters, including blanks, 
 * contained in a string. Do not include the end-of-string NULL marker in the count.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Size = 256;

void
GetLine(char bufferString[], int size);

int
GetCharCount(char bufferString[], int size);

int
main()
{
	char BufferString[Size] = { 0 };

	printf("Enter in a string of text:\n");
	GetLine(BufferString, Size);
	
	printf("Character count: %d\n", GetCharCount(BufferString, Size));

	return 0;
}

void
GetLine(char bufferString[], int size)
{
	int i = 0;
	while (i < (size - 1) && (bufferString[i++] = getchar()) != '\n')
	{
		// continue getting characters ...
	}
	bufferString[i] = '\0';
}

int
GetCharCount(char bufferString[], int size)
{
	int result = 0;
	for (int i = 0; i < size && bufferString[i] != '\0'; ++i)
	{
		++result;
	}
	return result;
}

