/*
 * Enter and execute Program 10.11 on your computer.
 *
 */

#include <stdlib.h>
#include <stdio.h>

#define HOLIDAY 20
#define TRUE 1
#define FALSE 0

int htable[HOLIDAY];

int
isHoliday(int testDate);

int
getHolidays();

int
main()
{
	int month, day, year, testDate;

	printf("Enter a month, day, and year: ");
	scanf("%d %d %d", &month, &day, &year);
	testDate = year * 10000 + month * 100 + day;

	if (isHoliday(testDate))
	{
		printf("This date is a holiday.\n");
	}
	else
	{
		printf("This date is not a holiday.\n");
	}

	return 0;
}

int
isHoliday(int testDate)
{
	int i;
	if (htable[0] == 0)
	{
		getHolidays();
	}
	for (i = 0; i < HOLIDAY; i++)
	{
		if (testDate == htable[i])
		{
			return TRUE;
		}
	}
	return FALSE;
}

int
getHolidays()
{
	char *HolidayFile = "./data/holidays.txt";
	int i = 0;
	int month, day, year;
	char del1, del2;
	FILE *inFile;
	inFile = fopen(HolidayFile, "r");
	if (inFile == NULL)
	{
		printf("\nFailed to open the file.\n");
		exit(1);
	}
	while (fscanf(inFile, "%d%c%d%c%d", &month, &del1, &day, &del2, &year) != EOF)
	{
		htable[i++] = year * 10000 + month * 100 + day;
	}
	fclose(inFile);
	return i;
}
