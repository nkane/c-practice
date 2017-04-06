/*
 * Write a C program that first determines if an entered character is a lowercase
 * letter. If the letter is lowercase, determine and print out its position in the
 * alphabet. For example, if the entered letter is c, the program should print out
 * 3, since c is the third letter in the alphabet. (Hint: If the entered character
 * is lowercase, its position can be determined by subtracting "a" from the letter
 * and adding 1
 *
 * In addition, handle uppercase letters as well.
 */

#include <stdio.h>

inline int
DetermineAlphabetPosition(char);

int
main(void)
{
	char c;
	printf("Enter in a character:\n");
	scanf("%c", &c);
	
	printf("The letter %c is at position: %d\n", c, DetermineAlphabetPosition(c));
	
	return 0;
}

inline int
DetermineAlphabetPosition(char c)
{
	int result = 0;

	if (c >= 'a' && c <= 'z')
	{
		result =  ((int)c - (int)'a') + 1;
	}
	else if (c >= 'A' && c <= 'Z')
	{
		result = ((int)c - (int)'A') + 1;
	}

	return result;
}
