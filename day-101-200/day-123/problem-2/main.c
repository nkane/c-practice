/*
 * Enter, compile, and execute Program 10.10
 *
 */

#include <stdlib.h>
#include <stdio.h>

#define HOLIDAYS 20

int htable[HOLIDAYS];

int
getHolidays();

int
main()
{
	int i, numberHolidays;

	numberHolidays = getHolidays();

	printf("The Holiday array contains %d holidays\n", numberHolidays);
	printf(" and contains the elements:\n");
	for (i = 0; i < numberHolidays; i++)
	{
		printf("%d\n", htable[i]);
	}

	return 0;
}

int
getHolidays()
{
	char HolidayFile[] = "./data/holidays.txt";
	int i = 0; 
	int month, day, year;
	char del1, del2;
	FILE *inFile;
	inFile = fopen(HolidayFile, "r");
	if (inFile == NULL)
	{
		printf("\nFailed to open the file.\n");
	}
	while (fscanf(inFile, "%d%c%d%c%d", &month, &del1, &day, &del2, &year) != EOF)
	{
		htable[i++] = year * 10000 + month * 100 + day;
	}
	fclose(inFile);
	return i;
}

