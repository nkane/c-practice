/*
 * Create a function named cvowels() the counts and returns the number of vowels
 * in a passed string.
 * 
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define Size 512

int
CountVowels(char *stringBuffer);

bool
IsVowel(char c);

int
main()
{
	char StringBuffer[Size] = { 0 };

	printf("Enter in a string: ");

	gets(StringBuffer);

	int count = CountVowels(StringBuffer);

	printf("Vowel count: %d\n", count);

	return 0;
}


int
CountVowels(char *stringBuffer)
{
	int count = 0;
	for (int i = 0; *(stringBuffer + i) != '\0'; ++i)
	{
		if (IsVowel(*(stringBuffer + i)))
		{
			++count;
		}
	}
	return count;
}

bool
IsVowel(char c)
{
	bool result = false;
	c = tolower(c);
	switch (c)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		{
			result = true;
		} break;
		default:
		{
		} break;
	}
	return result;
}
