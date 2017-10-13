/*
 * Rewrite Program 10.7 so that the origin for the fseek() function used
 * in the for loop is the start of the file rather than the end. The program
 * should still print the file in reverse order.
 *
 */

#include <stdlib.h>
#include <stdio.h>

int
main()
{
	int ch, n;
	long int offset, last;
	FILE *inFile;

	inFile = fopen("./data/test.dat", "r");
	if (inFile == NULL)
	{
		printf("\nFailed to open the test.dat file.\n");
		exit(1);
	}
	fseek(inFile, 0L, SEEK_END);
	last = ftell(inFile);
	for (offset = 0; offset <= last; offset++)
	{
		//fseek(inFile, -offset, SEEK_END);
		fseek(inFile, -(last - offset), SEEK_END);
		ch = getc(inFile);
		switch (ch)
		{
			case '\n':
			{
				printf("LF : ");
			} break;

			case EOF:
			{
				printf("EOF: ");
			} break;

			default:
			{
				printf("%c : ", ch);
			} break;
		}
	}
	fclose(inFile);

	printf("\n");
	system("pause");

	return 0;
}
