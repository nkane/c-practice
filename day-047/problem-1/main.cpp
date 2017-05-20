/*
 * Print the decimal, octal, and hexidecimal values of all characters between the start and
 * stop characters entered by a user. For example, if the user enters an a and z, the program
 * should print all the characters between a and z and their respective numerical values. Make
 * sure that the second character entered by the user occurs later in the alphabet than the first
 * character. If it does not, write a loop that repeatedly asks the user for a valid second
 * character until one is entered.
 *
 */

#include <stdio.h>
#include <ctype.h>

int
main()
{
	char inputOne = ' ';
	char inputTwo = ' ';

	do {
		printf("Enter start value:\n");
		scanf("\n%c", &inputOne);

		inputOne = tolower(inputOne);

		printf("char %c - value: %d\n", inputOne, (int)inputOne);
		
		printf("Enter end value:\n");
		scanf("\n%c", &inputTwo);

		inputTwo = tolower(inputTwo);

		printf("char %c - value: %d\n\n", inputTwo, (int)inputTwo);

	} while(inputOne > inputTwo);


	int start = (int)inputOne;
	int end = (int)inputTwo;

	while (start <= end)
	{
		printf("Char: %c\n", (char)start);
		printf("Int:  %d\n", start);
		printf("Hex:  %x\n", start);
		printf("Oct:  %o\n", start);
		printf("\n\n");
		++start;
	}

	return 0;
}
