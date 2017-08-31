/*
 * Write a C function named TrimFront() that deletes all leading blanks from a string.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))
#define Size 100

void
GetLine(char *stringBuffer, int size);

void
TrimFront(char *stringBuffer, int size);

int
main()
{
	char StringBuffer[Size] = { 0 };

	printf("Enter in a string:\n");
	GetLine(StringBuffer, len(StringBuffer));
	
	printf("Current String:\n%s", StringBuffer);

	TrimFront(StringBuffer, Size);

	printf("After Front Trim:\n%s", StringBuffer);

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
TrimFront(char *stringBuffer, int size)
{
	int headPosition = -1;
	int lastPosition = 0;
	while (*(stringBuffer + lastPosition++) != '\0')
	{
		if (*(stringBuffer + lastPosition) != ' ' && headPosition == -1)
		{
			headPosition = lastPosition;
		}
	}

	int i = 0;
	while (*(stringBuffer + i) != '\0')
	{
		if (headPosition < lastPosition)
		{
			*(stringBuffer + i) = *(stringBuffer + headPosition++);
		}
		else
		{
			*(stringBuffer + i) = '\0';
			break;
		}
		++i;
	}
}

