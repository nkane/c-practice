/*
 * Write a declaration to store the string "This is a test"
 * into an array named stringtest. Include the declaration
 * in a program to display the message using the following
 * loop: 
 *
 * 	for (i = 0; i <= 14; i++)
 * 		printf("%c", stringtest[i]);
 *
 * Include a separate loop that only displays the characters
 * t, e, s, and t.
 *
 * Write another loop (using a while loop) that will iterate
 * over each character of the string. 
 *
 */

#include <stdio.h>

#define array_size(array)(sizeof(array)/sizeof(array[0]))

int
main()
{
	char stringtest[] = "This is a test\0";

	for (int i = 0; i <= 14; ++i)
	{
		printf("%c", stringtest[i]);
	}

	// add spacing
	printf("\n");

	for (int i = 0; i <= array_size(stringtest); ++i)
	{
		switch (stringtest[i])
		{
			case 't':
			case 'e':
			case 's':
			{
				printf("%c", stringtest[i]);
			} break;
		}
	}

	// add spacing
	printf("\n");

	int i = 0;
	char c = NULL;
	while ((c = *(stringtest + i)) != NULL)
	{
		printf("%c", c);
		++i;
	}

	return 0;
}
