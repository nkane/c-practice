/*
 * Write a C function named delChar() that can be used to delete characters from a string.
 * The function should accept three arguments: the string name, the number of characters to
 * delete, and the starting position in the string where characters should be deleted.
 * For example, the function call delChar(string, 13, 5), when applied to the string
 * "all enthusiastic people", should result in the string "all people".
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Size = 256;

void
GetLine(char bufferString[], int size);

void
DeleteChar(char bufferString[], int deleteLength, int startingPosition);

int
main()
{
	int deletePosition = 0;
	int deleteLength = 0;
	char BufferString[Size] = { 0 };

	printf("Enter in a string:\n");
	GetLine(BufferString, Size);

	printf("Enter in a position to start deleting: ");
	scanf("%d", &deletePosition);

	printf("Enter in a delete length: ");
	scanf("%d", &deleteLength);

	printf("Before: %s", BufferString);

	DeleteChar(BufferString, deleteLength, (deletePosition - 1));

	printf("After: %s", BufferString);

	return 0;
}

void
GetLine(char bufferString[], int size)
{
	int i = 0;
	while ((i < (size - 1)) && ((bufferString[i++] = getchar()) != '\n'));
	bufferString[i] = '\0';
}

void
DeleteChar(char bufferString[], int deleteLength, int startingPosition)
{
	char tempBuffer[Size] = { 0 };
	char currentLength = 0;
	int j = 0;
	int i = 0;
	while (i < Size && bufferString[j] != '\0')
	{
		if (j == startingPosition)
		{
			j = startingPosition + deleteLength;
		}
		else
		{
			tempBuffer[i] = bufferString[j];
			++j;
			++i;
		}
	}

	for (int i = 0; i < Size && bufferString[i] != '\0'; ++i)
	{
		bufferString[i] = tempBuffer[i];
	}
}

