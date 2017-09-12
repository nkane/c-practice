/*
 * Write a function to count the number sentences entered; assume a sentence ends
 * in either a period, question mark, or exclamation point. (Hint: you will not 
 * be able to use gets() to input the sentences, because gets() ends input on receipt
 * of the first newline character.)
 *
 */

#include <stdio.h>

#define Size 1000

void
GetString(char *stringBuffer, int max);

int
CountSentences(char *stringBuffer, int max);

int
main()
{
	char StringBuffer[Size] = { 0 };

	printf("Enter in a string of text (EOF, ends):\n");
	GetString(StringBuffer, Size);
	printf("Sentence count: %d\n", CountSentences(StringBuffer, Size));

	return 0;
}

void
GetString(char *stringBuffer, int max)
{
	int i = 0;
	while (i < (max - 1) && (*(stringBuffer + i) = getchar()) != EOF)
	{
		++i;
	}
	*(stringBuffer + i) = '\0';
}


int
CountSentences(char *stringBuffer, int max)
{
	int i = 0;
	int count = 0;
	char c;
	while (i < (max - 1) && *(stringBuffer + i) != '\0')
	{
		c = *(stringBuffer + i);
		if (c == '.' || 
		    c == '?' ||
		    c == '!')
		{
			++count;
		}
		++i;
	}
	return count;
}

