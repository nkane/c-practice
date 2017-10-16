/*
 * Write a C program that will read and display every second character
 * in a file named test.dat
 *
 */

#include <stdio.h>

int
main()
{
	FILE *file = NULL;
	file = fopen("./data/test.dat", "r");

	if (file)
	{
		long int index = ftell(file);
		char c;
		while ((c = fgetc(file)) != EOF)
		{
			if ((index % 2) != 0)
			{
				printf("%c", c);
			}
			index = ftell(file);
		}
		fclose(file);
	}

	return 0;
}
