/*
 * The function fseek() returns 0 if the poisition specified has been reached,
 * or if the position specified was beyond the file's boundaries. Modify program
 * 10.7 to display an error message if fseek() return 1.
 *
 */

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
	last = ftell(inFile) + 1;
	int result = 0;
	for (offset = 0; offset <= last; offset++)
	{
		if ((result = fseek(inFile, -offset, SEEK_END)) != 0)
		{
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
		else
		{
			printf("ERROR: out of file's boundaries\n");
			break;
		}
	}
	fclose(inFile);

	return 0;
}
