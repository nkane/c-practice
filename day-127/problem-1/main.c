/*
 * Pollen count readings, which are taken from August through September in the 
 * northeastern region of the United States, measure the number of ragweed pollen
 * grains in the air. Pollen countds in the range of 10 to 200 grains per cubic
 * meter of air are typical during this time of year. Pollen counts above 10 begin
 * to affect a small percentage of hay fever sufferers, counts in the range of 30
 * to 40 will noticeably bother approximately 30 percent of hay fever suffers,
 * and counts between 40 and 50 adversely affect more than 60 percent of all
 * hay fever sufferers.
 * 
 * Write a C program that updates a file containing the 10 most recent pollen counts.
 * Add each new count to the end of the file. As you add a new count to the end of
 * the file, delete the oldest count, which is the first value in the file. Your
 * program should also calculate and display the averages of the data for the old
 * and new files.
 * 
 * To test your program, first create a file named pollen.dat that contains the
 * following pollen count data: 30, 60, 40, 80, 90, 120, 150, 130, 160, 170. Here
 * the first value, 30, corresponds to the oldest pollen count, and the last value,
 * 170, corresponds to the most recent pollen count. The pseudocode for the file
 * update program is
 *
 * Display a message indicating what the program does
 * Request the name of the data file
 * Request a new pollen count reading
 * Open the data file as an input file
 * Do for 10 data items
 *    Read a value into an array
 *    Add the value to a total
 * EndDo
 * Close the file
 * Open the file as an output file
 * Calculate and display the old 10-day average
 * Calculate and display the new 10-day average
 * Write the nine most recent pollen counts from the array to the file
 * Write the new pollen count to the file
 * Close the file
 *
 */

#include <stdlib.h>
#include <stdio.h>

FILE *
OpenDataFile();

void
ReadCurrentValues(FILE *dataFile, int outData[10]);

void
InputData(FILE *dataFile, int rawData[10]);

float
ComputeDataAverage(int rawData[10]);

int
main()
{
    FILE *pollenData = OpenDataFile();
    if (pollenData)
    {
        int rawData[10] = { 0 };
        char c;
	float currentAverage = 0.0f;
        ReadCurrentValues(pollenData, rawData);
        do {
            printf("Write new data?\n");
	    scanf(" %c", &c);
	    c = tolower(c);
            if (c == 'y')
            {
                InputData(pollenData, rawData);
            }
	    currentAverage = ComputeDataAverage(rawData);
	    printf("Current Average: %6.2f\n", currentAverage);
        } while (c == 'y');
        fclose(pollenData);
    }
    system("pause");
    return 0;
}

FILE *
OpenDataFile()
{
    FILE *dataFile = NULL;
    dataFile = fopen("./data/pollen.dat", "r+");
    return dataFile;
}

void
ReadCurrentValues(FILE *dataFile, int outData[10])
{
    int i = 0;
    while (fscanf(dataFile, "%d\n", &outData[i]) != EOF && i < 10)
    {
        ++i;
    }
}

void
InputData(FILE *dataFile, int rawData[10])
{
	int inputData = 0;
	printf("Enter new pollen count: ");
	scanf("%d", &inputData);
	int i;
	for (i = 1; i < 10; ++i)
	{
		rawData[i - 1] = rawData[i];
	}
	rawData[--i] = inputData;
	fseek(dataFile, 0, SEEK_SET);
	i = 0;
	while (i < 10) 
	{
		fprintf(dataFile, "%d\n", rawData[i++]);
	}
}

float
ComputeDataAverage(int rawData[10])
{
	float average = 0;
	int i;
	for (i = 0; i < 10; ++i)
	{
		average += rawData[i];
	}
	average /= 10.0f;
	return average;
}
