/*
 * Modify the vowels() function given in Exercise 1 to count and display the 
 * individual numbers of each vowel contained in the string.
 *
 */

#include <ctype.h>
#include <stdio.h>

#define global_variable static

struct Item
{
	char key;
	int  value;
};

global_variable const int Size = 256;
global_variable const int Set_Size = 5;

global_variable Item HashSet[Set_Size] = 
{
	{ 'a', 0, },
	{ 'e', 0, },
	{ 'i', 0, },
	{ 'o', 0, },
	{ 'u', 0, },
};

int
GetCharKey(char c);

void
GetLine(char string[], int size);

void
vowels(char string[]);

int
main()
{
	char stringBuffer[Size] = { 0 };

	printf("Enter in a string:\n");
	GetLine(stringBuffer, Size);
	vowels(stringBuffer);

	for (int i = 0; i < Set_Size; ++i)
	{
		printf("%c : %d\n", HashSet[i].key, HashSet[i].value);
	}

	return 0;
}

void
GetLine(char string[], int size)
{
	int i = 0;
	while (i < (size - 1) && (string[i++] = getchar()) != '\n')
	{
		// continue to process characters ...
	}
	string[i] = '\0';
}

void
vowels(char string[])
{
	int i = 0;
	char c;
	int currentKey;
	while ((c = string[i++]) != '\0')
	{
		c = tolower(c);
		currentKey = GetCharKey(c);
		if (currentKey >= 0)
		{
			HashSet[currentKey].value++;
		}
	}
}

int
GetCharKey(char c)
{
	int result = -1;
	switch (c)
	{
		case 'a':
		{
			result = 0;
		} break;

		case 'e':
		{
			result = 1;
		} break;

		case 'i':
		{
			result = 2;
		} break;

		case 'o':
		{
			result = 3;
		} break;

		case 'u':
		{
			result = 4;
		} break;
	}
	return result;
}

