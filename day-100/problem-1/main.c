/*
 * Enter and execute Program 9.6 on your computer.
 */

#include <ctype.h>
#include <stdio.h>

#define Size 100

void
ConvetToUpper(char message[]);

int
main()
{
	char Message[Size] = { 0 };

	printf("\nType in any sequence of characters:\n");
	gets(Message);

	ConvetToUpper(Message);

	printf("The characters just entered, in uppercase are:\n%s\n", Message);

	return 0;
}
void
ConvetToUpper(char message[])
{
	int i;
	for (i = 0; message[i] != '\0'; ++i)
	{
		message[i] = toupper(message[i]);
	}
}

