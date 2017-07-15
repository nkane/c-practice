/*
 * Write a program that has a declaration in main() to store the string 
 * "Vacation is near" into an array named message. There should be a function
 * call to display() that accepts a message in a parameter named string and
 * then display the contents of the message.
 *
 * Modify the display() function written in the above to display the first
 * eight elements of the message array.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

void
Display(char message[], int length);

int
main()
{
	char message[] = "Vaction is near\0";

	Display(message, len(message));
	Display(message, 8);

	return 0;
}

void
Display(char message[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%c", *(message + i));
	}
	printf("\n");
}

