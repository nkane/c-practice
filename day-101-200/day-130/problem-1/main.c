/*
 * Write, compile, and run a C program that creates a binary file name grades.bin 
 * and writes the following five lines of data to the file:
 *
 * 	90.3    92.7    90.3    99.8
 * 	85.3    90.5    87.3    90.8
 * 	93.2    88.4    93.8    75.6
 * 	82.4    95.6    78.2    90.0
 * 	93.5    80.2    92.9    94.4
 *
 * Using the data in the grades.bin file created - write, compile, and run a C
 * program that reads, computes, and displays the average of each group of four
 * grades.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

FILE *
CreateFile(const char *fileName);

void
WriteData(FILE *dataFile);

void
ProcessGradeFile(FILE *dataFile);

void
AverageByGroup(float data[20], int groupSize);

int
main()
{
	printf("Program will create or overwrite grades.bin file and read / compute average grade in groups of four.\n");
	FILE *gradeFile = CreateFile("grades.bin");
	if (gradeFile)
	{
		ProcessGradeFile(gradeFile);
		fclose(gradeFile);
	}
	system("pause");
	return 0;
}

FILE *
CreateFile(const char *fileName)
{
	FILE *file = fopen(fileName, "rb");
	char c = ' ';
	if (file)
	{
		printf("Overwrite file? (y/n): ");
		scanf("%c", &c);
		if (c == 'y')
		{
			fclose(file);
		}
	}
	if (file == NULL || tolower(c) == 'y')
	{
		file = fopen(fileName, "wb");
		WriteData(file);
		fclose(file);
		file = fopen(fileName, "rb");
	}
	return file;	
}

void
WriteData(FILE *dataFile)
{
	float gradeData[SIZE] =
	{
		90.3, 92.7, 90.3, 99.8,
		85.3, 90.5, 87.3, 90.8,
		93.2, 88.4, 93.8, 75.6,
		82.4, 95.6, 78.2, 90.0,
		93.5, 80.2, 92.9, 94.4, 
	};
	fwrite(gradeData, sizeof(float), SIZE, dataFile);
}

void
ProcessGradeFile(FILE *dataFile)
{
	float gradeData[SIZE] = { 0.0f };
	fread(gradeData, sizeof(float), SIZE, dataFile);
	AverageByGroup(gradeData, 4);
}

void
AverageByGroup(float data[20], int groupSize)
{
	int i;
	int count = 1;
	float average = 0.0f;
	for (i = 0; i < SIZE; ++i)
	{
		average += data[i];
		if ((i + 1) % groupSize == 0)
		{
			printf("Group %d Average: %6.2f\n", count, (average / groupSize));
			++count;
			average = 0.0f;
		}
	}
}
