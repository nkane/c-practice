/*
 * Write a C function that reverses the characters in a string. (Hint: this can
 * be considered as a string copy starting from the back end of the first string.)
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Size = 256;

void
GetLine(char bufferString[], int size);

void
ReverseString(char bufferString[], int size);

int
main()
{
	char BufferString[256] = { 0 };

	printf("Enter in a string:\n");
	GetLine(BufferString, Size);
	ReverseString(BufferString, Size);

	printf("%s", BufferString);

	return 0;
}

void
GetLine(char bufferString[], int size)
{
	int i = 0;
	while (i < (size - 1) && (bufferString[i++] = getchar()) != '\n');
	bufferString[i - 1] = '\0';
}

void
ReverseString(char bufferString[], int size)
{
	// find the end of the string
	int end = 0;
	int mid = 0;
	while (end < (size - 1) && bufferString[end] != '\0')
	{
		++end;
	}
	mid = (end / 2);
	end -= 1;
	char temp;
	for (int i = 0; i < mid; ++i)
	{
		temp = bufferString[i];
		bufferString[i] = bufferString[end];
		bufferString[end] = temp;
		--end;
	}
}

