/*
 * Read the data file associated with this problem and complete the following:
 *
 * Write a C program to calculate and display the average of each group of numbers in
 * the file created. The data is arranged in the file so that each group of numbers is
 * preceded by the number of data items in the group. Thus, the first number in the file,
 * 5, indicates that the next five numbers should be grouped together. The number 4 indicates
 * that the following for numbers are a group, and the 6 indicates that the last six numbers
 * are a group. (Hint: use a nested loop. The outter loop should terimate when the EOF marker
 * is encountered.)
 *
 */

#include <stdlib.h>
#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

void
ClearBuffer(char *buffer, int size);

int
main()
{
	FILE *readFile = NULL;
	char stringBuffer[128] = { 0 };

	if (readFile = fopen("./data/test.dat", "r"))
	{
		int numberCount = 0;
		int i = 0;
		int j = 0;
		char tempBuffer[3];
		while (fgets(stringBuffer, len(stringBuffer), readFile) != NULL)
		{
			int positionCount = 0;
			int currentNumber = 0;
			int average = 0;
			while (*(stringBuffer + i) != '\0')
			{
				if (j < numberCount) 
				{
					if (*(stringBuffer + i) != ' ' && *(stringBuffer + i ) != '\n')
					{
						tempBuffer[positionCount] = *(stringBuffer + i);
						++positionCount;
					}
					else
					{
						currentNumber = atoi(tempBuffer);
						ClearBuffer(tempBuffer, len(tempBuffer));
						printf(" %d ", currentNumber);
						average += currentNumber;
						positionCount = 0;
						++j;
						if (j == numberCount) 
						{
							j = 0;
							currentNumber = 0;
							printf("\nAverage: %6.2f\n\n", ((float)average / (float)numberCount));
							numberCount = 0;
							average = 0;
						}
					}
					++i;
				}
				else
				{
					ClearBuffer(tempBuffer, len(tempBuffer));
					tempBuffer[0] = stringBuffer[i];
					i += 2;
					numberCount = atoi(tempBuffer);
					ClearBuffer(tempBuffer, len(tempBuffer));
					printf("Number Count: %d\n", numberCount);
				}
			}
		}
		fclose(readFile);
	}

	return 0;
}

void
ClearBuffer(char *buffer, int size)
{
	int i = 0;
	for (i = 0; i < size; ++i)
	{
		*(buffer + i) = '\0';
	}
}
