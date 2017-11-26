/*
 * Write a C program that includes a declaration in main() that stores the string
 * "Vacation is near" in an array named message. Include a function call to display()
 * the accepted message in a parameter named string and then display the message using
 * the pointer notation * (string + i).
 *
 * Modify the display function written to alter the address in message. Use the expression
 * *string rather thatn *(string + i) to retrieve the correct element.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

void
Display(char *string, int size);

void
DisplayAlter(char *string);

int
main()
{
	char message[] = "Vacation is near";

	Display(message, len(message));
	DisplayAlter(message);

	return 0;
}

void
Display(char *string, int size)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		printf("%c", *(string + i));
	}
	printf("\n");
}

void
DisplayAlter(char *string)
{
	while (*string != '\0')
	{
		printf("%c", *string++);
	}
	printf("\n");
}
