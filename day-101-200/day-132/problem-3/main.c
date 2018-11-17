/*
 * Write a program that stores the string "Hooray for All of Us" in an array
 * named strng. Use the declaration char strng[] = "Hooray for All of Us";, which
 * ensures that the end-of-string escape sequence \0 is included in the array. Display
 * the characters in the array by changing the address in a pointer called messPtr. Use
 * a for statement in  your program.
 *
 * Modify the program to use the while statement while (*messPtr != '\0').
 *
 * Modify the program to start the display with the word All.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

int
IndexOf(char *string, int size, char key);

int
main()
{
	char string[] = "Hooray for All of Us";
	char *messPtr;

	printf("For loop\n");
	for (messPtr = string; messPtr < (string + len(string)); ++messPtr)
	{
		printf("%c", *messPtr);
	}

	printf("\nWhile loop\n");
	messPtr = string;
	while (messPtr < (string + len(string)))
	{
		printf("%c", *messPtr);
		++messPtr;
	}

	printf("\nLoop starting at All\n");
	int i = IndexOf(string, len(string), 'A');
	for (messPtr = (string + i); messPtr < (string + len(string)); ++messPtr)
	{
		printf("%c", *messPtr);
	}

	return 0;
}

int
IndexOf(char *string, int size, char key)
{
	int result = -1;
	int i;
	for (i = 0; i < size; ++i)
	{
		if (*(string + i) == key)
		{
			result = i;
			break;
		}
	}
	return result;
}
