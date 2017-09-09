/*
 * Write a C function named addChar() to insert one string of characters into another
 * string. The function should accept three arguments the string to be inserted, the
 * original string, and the position in the original string where the insertion should
 * begin. For example, the call addChar("for all", message, 6) should insert the characters
 * for all in message starting at message[5]
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Size = 256;

void
GetLine(char bufferString[], int size);

void
AddChar(char newBufferString[], char originalBufferString[], int position);

int
main()
{
	char BufferStringPrimary[Size] = { 0 };
	char BufferStringSecondary[Size] = { 0 };
	int i = 0;

	printf("Enter in a string:\n");
	GetLine(BufferStringPrimary, Size);

	printf("Enter in a string to combined to previous:\n");
	GetLine(BufferStringSecondary, Size);

	printf("Enter starting position to merge string: ");
	scanf("%d", &i);

	AddChar(BufferStringSecondary, BufferStringPrimary, i);

	printf("%s", BufferStringPrimary);

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
AddChar(char newBufferString[], char originalBufferString[], int position)
{
	int i = 0;
	--position;
	while (newBufferString[i] != '\0')
	{
		originalBufferString[position] = newBufferString[i];
		++position;
		++i;
	}
}

