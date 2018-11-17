/*
 * Write a C function named chartype() that determines the ASCII type of any 
 * integer in the range 0 to 127. If the number represents a printable ASCII
 * character, print the character with one of the following appropriate messages:
 *
 * 	- The ASCII character is a lowercase letter.
 * 	- The ASCCI character is an uppercase letter.
 *	- The ASCII character is a digit.
 *	- The ASCII character is a punctuation mark.
 *	- The ASCII character is a space.
 *
 * If the ASCII character is a nonprintable character, display its ASCII code in decimal
 * format and the message,  The ASCII character is a nonprintable character.
 *
 * Generate 20 random numbers in the range 0 to 127 and call chartype() for each generated
 * number.
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Size 20

int
GenerateNumber();

void
OutputASCII(int x);

int
main()
{
	int TestCase[Size] = { 0 };
	int i = 0;

	srand(time(NULL));

	for (i = 0; i < Size; ++i)
	{
		TestCase[i] = GenerateNumber();
	}
	
	for (i = 0; i < Size; ++i)
	{
		OutputASCII(TestCase[i]);
	}

	return 0;
}

int
GenerateNumber()
{
	return (rand() % 128);
}

void
OutputASCII(int x)
{

	printf("Char: %c - Int: %d\n", (char)x, x);
	// initial check within ASCII range
	if (x >= 0 && x <= 127)
	{
		if (x >= 'A' && x <= 'Z')
		{
			printf("The ASCII character is a uppercase letter.\n");
		}
		else if (x >= 'a' && x <= 'z')
		{
			printf("The ASCII character is a lowercase letter.\n");
		}
		else if (x >= '0' && x <= '9')
		{
			printf("The ASCII character is a digit.\n");
		}
		else if (x > ' ')
		{
			printf("The ASCII character is a punctuation mark.\n");
		}
		else if (x == ' ')
		{
			printf("The ASCII character is a space.\n");
		}
		else 
		{
			printf("The ASCII character is a formatter.\n");
		}
	}
	else
	{
		printf("Invalid ASCII Code: %d\n", x);
	}
	printf("\n");
}

