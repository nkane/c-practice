/*
 * Modify the countword() function in Program 9.11 to also count the number of
 * letters each word and then return the average number of characters per word.
 * Name the modified function avgCharPerWord().
 *
 */

#include <stdbool.h>
#include <stdio.h>

#define Size 1000

int
AverageCharPerWord(char *stringBuffer);

int
main()
{
	char StringBuffer[Size] = { 0 };

	printf("Type in any number of word: ");
	gets(StringBuffer);

	printf("The average number of characters per word is %d\n", AverageCharPerWord(StringBuffer));

	system("pause");

	return 0;
}

int
AverageCharPerWord(char *stringBuffer)
{
	bool inWord = false;
	int wordCount = 0;
	int average = 0;
	int letterCount = 0;
	for (int i = 0; *(stringBuffer + i) != '\0'; ++i)
	{
		if (*(stringBuffer + i) == ' ')
		{
			inWord = false;
		}
		else if (inWord == false)
		{
			inWord = true;
			++wordCount;
		}
		if (*(stringBuffer + i) != ' ' )
		{
			++letterCount;
		}
	}
	printf("Total Characters: %d\n", letterCount);
	average = (letterCount / wordCount);
	return average;
}

