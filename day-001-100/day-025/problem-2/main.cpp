/*
 * Write a C program that accepts a character using the scanf() function and
 * determines if the character is a lowercase letter. A lowercase letter is any
 * character that is greater than or equal to "a" and less than or equal to "z".
 * If the entered character is a lowercase letter, display the message:
 * - "The character just entered is a lowercase letter."
 *
 * If the entered character is not lowercase, display the message:
 * - "The character just entered is not a lowercase letter."
 *
 * In addition to this, handle uppercase values as well printing similar messages.
 */

#include <stdio.h>

int
main(void)
{
	char c;
	printf("Enter in a character:\n");
	scanf("%c", &c);

	if (c >= 'a' && c <= 'z')
	{
		printf("The character entered is a lowercase letter!\n");
	}
	else 
	{
		if (c >= 'A' && c <= 'Z')
		{
			printf("The character entered is uppercase!\n");
		}
		else
		{
			printf("The character entered is not a lowercase letter!\n");
		}
	}
	
	return 0;
}
