/*
 * It has been said that a monkey pushing keys at random on a keyboard, could produce the
 * work of Shakespeare, given sufficient time. Simulate this by having a program select and
 * display letters at random. Count the number of letters typed until the program produces
 * one of the two-letter words:
 * 	- at, is, he, we, up, or on
 *
 * when one of these words is produced, stop the program and display the total number of 
 * letters typed. (Hint: Choose a letter by selecting a random integer number between 1 
 * and 26)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define array_len(array)(sizeof(array)/sizeof(array[0]))

#define global_varaible static

global_varaible const int Min = 97;
global_varaible const int Max = 122;
global_varaible bool IsGenerating = true;
global_varaible char CurrentLetters[3];

int 
GenerateNumber(int, int);

bool 
ValidString(char *);

int
main()
{
	int count = 0;
	srand(time(NULL)); 
	while (IsGenerating)
	{
		for (int i = 0; i < array_len(CurrentLetters); ++i)
		{
			if ((i + 1) == array_len(CurrentLetters)) 
			{
				CurrentLetters[i] = '\0';
			}
			else 
			{
				CurrentLetters[i] = (char)GenerateNumber(Min, Max);
			}
		}

		printf("Generated: %s\n", CurrentLetters);

		IsGenerating = !ValidString(CurrentLetters);
		count += 2;
	}

	printf("\nTotal Letters Types: %d\n", count);
	printf("Found Word: %s\n", CurrentLetters);

	system("pause");

	return 0;
}

int 
GenerateNumber(int min, int max)
{
	int result = 0;
	result = rand();
	result %= max;
	if (result < min)
	{
		result = GenerateNumber(min, max);
	}
	return (result);
}

bool 
ValidString(char *string)
{
	switch (*string)
	{
		case 'a':
		{
			++string;
			if (*string == 't')
			{
				return true;
			}
		} break;

		case 'i':
		{
			++string;
			if (*string == 's')
			{
				return true;
			}
		} break;

		case 'h':
		{
			++string;
			if (*string == 'e')
			{
				return true;
			}
		} break;
		
		case 'w':
		{
			++string;
			if (*string == 'e')
			{
				return true;
			}
		} break;

		case 'u':
		{
			++string;
			if (*string == 'p')
			{
				return true;
			}
		} break;

		case 'o':
		{
			++string;
			if (*string == 'n')
			{
				return true;
			}
		} break;

		default:
		{

		} break;
	}

	return false;
}

