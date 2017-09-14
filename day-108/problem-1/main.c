/*
 * Modify the function written for Exercise 6 to count the number of words as well as the
 * number of sentences. The function should return the average words per sentence.
 *
 */

#include <stdbool.h>
#include <stdio.h>

#define Size 1000

typedef struct _result
{
	int Sentences;
	int Words;
} Result;

void
GetString(char *stringBuffer, int max);

Result *
Process(char *stringBuffer);

int
main()
{
	char StringBuffer[Size] = { 0 };
	Result *R = NULL; 

	printf("Enter in a string of text (EOF, ends):\n");
	GetString(StringBuffer, Size);

	R = Process(StringBuffer);

	if (R) 
	{
		printf("Sentences: %d\n", R->Sentences);
		printf("Words: %d\n", R->Words);
		free(R);
	}
	else
	{
		printf("Ouch! something went wrong!\n");
	}

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


Result *
Process(char *stringBuffer)
{
	Result *r = (Result *)malloc(sizeof(Result));
	r->Sentences = 0;
	r->Words = 0;
	int i = 0;
	char c;
	bool inWord = false;
	bool lastCharPunc = false;
	while (*(stringBuffer + i) != '\0')
	{
		c = *(stringBuffer + i);
		switch (c)
		{
			case '.':
			case '?':
			case '!':
			{
				if (!lastCharPunc)
				{
					++r->Sentences;
				}
				lastCharPunc = true;
			} break;
			case ' ':
			{
				inWord = false;
			} break;
			default: 
			{
				lastCharPunc = false;
				if (inWord == false)
				{
					inWord = true;
					++r->Words;
				}
			} break;
		}
		++i;
	}
	return r;
}

