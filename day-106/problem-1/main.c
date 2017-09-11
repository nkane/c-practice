/*
 * Modify the countchar() function in Program 9.10 to omit blank spaces from
 * the count.
 * 
 */

#include <stdio.h>

#define Size 1000

int
CountChar(char *stringBuffer, int max);

int
main()
{
	char StringBuffer[Size] = { 0 };
	int charCount = 0;

	printf("Type in any number of characters: ");

	gets(StringBuffer);
	charCount = CountChar(StringBuffer, Size);

	printf("The number of characters just entered is %d\n", charCount);

	return 0;
}

int
CountChar(char *stringBuffer, int max)
{
	int count = 0;
	for (int i = 0; *(stringBuffer + i) != '\0' && i < max; ++i)
	{
		if (*(stringBuffer + i) != ' ' && *(stringBuffer + i) != '\n')
		{
			++count;
		}
	}
	return count;
}

