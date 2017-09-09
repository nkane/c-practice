/*
 * The following function can be used to select and display all vowels contained
 * within a user-input string:
 *
 * void vowels(char string[])
 * {
 * 	int i = 0;
 * 	char c;
 *
 * 	while ((c = string[i++]) != '\0')
 * 	{
 * 		switch (c)
 * 		{
 * 			case 'a':
 * 			case 'e':
 * 			case 'i':
 * 			case 'o':
 * 			case 'u':
 * 				putchar(c);
 * 		}
 * 	}
 * 	putchar('\n');
 * }
 *
 * Noitce that the switch statement in vowels() uses the fact that selected cases "drop through"
 * in the absence of break statements. Thus, all selected cases result in a putchar() function
 * call. Include vowels() in a working program that accepts a user-input string and then displays
 * all vowels in the string. In response to the input How much is the little worth worth?, your
 * program should display ouieieoo.
 *
 * Modify the vowels() function to count and display the total number of vowels contained in the string
 * passed to it.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Size = 256;

void
GetLine(char string[], int bufferSize);

int
vowels(char string[]);

int
main()
{
	char stringBuffer[Size] = { 0 };

	printf("Enter in a string: \n");
	GetLine(stringBuffer, Size);

	printf("Vowel Count: %d\n", vowels(stringBuffer));

	return 0;
}

void
GetLine(char string[], int bufferSize)
{
	int i = 0;
	while (i < (bufferSize - 1) && (string[i++] = getchar()) != '\n')
	{
		// continues to process ...
	}
	string[i] = '\0';
}

int
vowels(char string[])
{
	int i = 0;
	int result = 0;
	char c;
	printf("\n");
	while ((c = string[i++]) != '\0')
	{
		switch (c)
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			{
				putchar(c);
				++result;
			};

		}
	}
	putchar('\n');
	return result;
}


