/*
 * Determine the operating system command or procedure provided by your computer to
 * display the contents of a saved file. Compare its operation with the program developed
 * for previous exercise. (Hint: in keyboard-driven operating systems, such as DOS and Unix,
 * the operating system command is typically dir, list, type, or cat.)
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

void
ReadFile(char *name);

void
ClearStringBuffer(char *stringBuffer);

bool
IsTerminatingCharacter(char c);

int
main(int argc, char *argv[])
{
	if (argc > 1)
	{
		ReadFile(argv[1]);
	}

	return 0;
}

void
ReadFile(char *fileName)
{
	FILE *readFile = NULL;
	char stringBuffer[256] = { 0 };
	char readContinue = '\0';
	if (readFile = fopen(fileName, "r"))
	{
		do
		{
			ClearStringBuffer(stringBuffer);
			fgets(stringBuffer, 256, readFile);
			if (IsTerminatingCharacter(*(stringBuffer + 0)))
			{
				break;
			}
			puts(stringBuffer);
			printf("continue (y/n) ...\n");
			scanf("\n%c", &readContinue);
			readContinue = tolower(readContinue);
		} while (readContinue == 'y');
		fclose(readFile);
	}
	else
	{
		printf("ERROR! Failed to open file: %s\n", fileName);
	}
}

void
ClearStringBuffer(char *stringBuffer)
{
	for (int i = 0; i < len(stringBuffer); ++i)
	{
		*(stringBuffer + i) = '\0';
	}
}

bool
IsTerminatingCharacter(char c)
{
	bool result = false;
	switch (c)
	{
		case '\0':
		case EOF:
		{
			result = true;
		} break;

		default:
		{

		} break;
	}
	return result;
}

