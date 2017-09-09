/*
 * Write a C function named TrimRear() that deletes all trailing bank from a string.
 *
 */

#include <stdio.h>

#define Size 100

int
GetLine(char *stringBuffer, int size);

void
TrimRear(char *stringBuffer, int length);

int
main()
{
	char StringBuffer[Size] = { 0 };

	printf("Enter in a string:\n");
	int length = GetLine(StringBuffer, Size);

	printf("Current string:\n%s", StringBuffer);

	TrimRear(StringBuffer, (length - 1));

	printf("After rear trim string:\n%s", StringBuffer);

	return 0;
}

int
GetLine(char *stringBuffer, int size)
{
	int i = 0;
	while (i < (size - 1) && (*(stringBuffer + i++) = getchar()) != '\n');
	*(stringBuffer + i) = '\0';
	return i;
}

void
TrimRear(char *stringBuffer, int length)
{
	while (length >= 0)
	{
		if (*(stringBuffer + length) == ' ')
		{
			*(stringBuffer + length) = '\0';
		}
		else if (*(stringBuffer + length) != '\n')
		{
			*(stringBuffer + (length + 1)) = '\n';
			 break;
		}
		--length;
	}
}

