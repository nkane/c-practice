/*
 * Write a C program that keeps track of the frequency of occurance of
 * each vowel as lines of text are typed at the keyboard. The end of
 * the text should be signified by entry of an EOF (end of file) marker
 * (ctrl z for DOS and ctrl d for Unix). The output of your program
 * should be a count of each vowel encountered in the input text.
 *
 * Add a function to the program written that displays a histogram of
 * the number of each vowel encountered. For example, if your program
 * detected the letter a five times, the letter e three times, the 
 * letter i two times, the letter o four times, and the letter u one
 * time, the histogram should appear as:
 *
 * 	a |***** 
 * 	e |*** 
 * 	i |** 
 *	o |*** 
 *	u |*
 *	  +----|----|-----|
 *	  0    5    10    15
 *
 */

#include <stdio.h>
#include <ctype.h>


void
OutputLine(char letter, int amount);

int
main()
{
	char c = '\0';

	int a = 0;
	int e = 0;
	int i = 0;
	int o = 0;
	int u = 0;

	// NOTE(nick): win32 EOF signal is Ctrl + Z and ENTER
	printf("Start entering in values: \n");
	do
	{
		c = getchar();
		switch (tolower(c)) 
		{
			case 'a':
			{
				++a;
			} break;

			case 'e':
			{
				++e;
			} break;

			case 'i':
			{
				++i;
			} break;

			case 'o':
			{
				++o;
			} break;

			case 'u':
			{
				++u;
			} break;
		}
	} while (c != EOF);

	printf("\n");
	OutputLine('a', a);
	OutputLine('e', e);
	OutputLine('i', i);
	OutputLine('o', o);
	OutputLine('u', u);
	printf("  +----|----|----|\n");
	printf("  0    5    10   15\n");

	return 0;
}

void
OutputLine(char letter, int amount)
{
	printf("%c |", letter);

	for (int i = 0; i < amount; ++i)
	{
		printf("*");
	}
	printf("\n");
}

