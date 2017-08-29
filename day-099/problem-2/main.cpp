/*
 * Write a C program that counts the number of words in a string. A word is encountered
 * whenever a transtition from a blank space to a nonblank character is encountered. Assume
 * the string contains any words separated by blank spaces.
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))
#define global_variable static

global_variable const int Size = 256;

void
GetLine(char *stringBuffer, int size);

int
WordCound(char *stringBuffer, int size);

bool
ValidChar(char c);

int
main()
{
	char StringBuffer[Size] = { 0 };

	printf("Enter in a string:\n");
	GetLine(StringBuffer, len(StringBuffer));

	int wordCount = WordCound(StringBuffer, len(StringBuffer));

	printf("Word Count: %d\n", wordCount);

	return 0;
}

void
GetLine(char *stringBuffer, int size)
{
	int i = 0;
	while (i < (size - 1) && (*(stringBuffer + i++) = getchar()) != '\n');
	*(stringBuffer + i) = '\0';
}

int
WordCound(char *stringBuffer, int size)
{
	int count = 0;
	bool isBlank = false;
	char c;

	if (ValidChar(*stringBuffer))
	{
		++count;
		for (int i = 0; i < (size - 1) && *(stringBuffer + i) != '\0'; ++i)
		{
			c = *(stringBuffer + i);
			if (c == ' ' || isBlank == true)
			{
				isBlank = true;
				if (ValidChar(c))
				{
					isBlank = false;
					++count;
				}
			}
		}
	}
	return count;
}


bool
ValidChar(char c)
{
	bool result = false;
	if ((c >= 'a' && c <= 'z') ||  (c >= 'A' && c <= 'Z'))
	{
		result = true;
	}
	return result;
}

