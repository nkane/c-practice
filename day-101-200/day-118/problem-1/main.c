/*
 * Create a file containg the following car number, number of miles driven,
 * and number of gallons of gas used by each car:
 *
 *	+----+--------+------+
 *	| 54 |   250  |  19  |
 *	+----+--------+------+
 *	| 62 |   525  |  38  |
 *	+----+--------+------+
 *	| 71 |   123  |   6  |
 *	+----+--------+------+
 *	| 85 |  1322  |  86  |
 *	+----+--------+------+
 *	| 97 |   235  |  14  |
 *	+----+--------+------+
 *
 * Write a C program the reads the data in the file created, and displays the car
 * number, miles driven, gallons used, and the miles per gallon for each car.
 * The output should additionally contain the total miles driven, total gallons
 * used and average miles per gallow for all the cards. These total should be 
 * displayed at the end of the output report.
 *
 */

#include <stdio.h>

typedef struct _record
{
	int Id;
	int MilesDriven;
	int GasUsed;
} Record;

int
main()
{
	FILE *readFile = NULL;

	if (readFile = fopen("./data/test.dat", "r"))
	{
		Record r = { 0 };
		float currentAvgMpg = 0.0f;
		int totalMiles = 0;
		int totalGallonsUsed = 0;
		while (fscanf(readFile, "%d,%d,%d ", &r.Id, &r.MilesDriven, &r.GasUsed) != EOF)
		{
			currentAvgMpg = ((float)r.MilesDriven / (float)r.GasUsed);
			totalMiles += r.MilesDriven;
			totalGallonsUsed += r.GasUsed;
			printf("Car ID: %d\n", r.Id);
			printf("Miles Driven: %d\n", r.MilesDriven);
			printf("Gas Used: %d\n", r.GasUsed);
			printf("Average MPG: %6.2f\n\n", currentAvgMpg);
		}
		printf("Total Miles Driven: %d\n", totalMiles);
		printf("Total Gallons Used: %d\n", totalGallonsUsed);
		printf("Total Average MPG: %6.2f\n", (float)totalMiles / (float)totalGallonsUsed);
		fclose(readFile);
	}

	system("pause");

	return 0;
}
