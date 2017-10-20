/*
 * Create a function named setHolidays() that reads and displays the current list
 * of holidays and then lets the user change, add, or delete holidays from the 
 * list. After a holiday has been modified, the function should sort the holidays and
 * display the new list. Finally the function should ask the user whether the new
 * list should be saved; if the user responds affirmatively, the function should write
 * the new data to the existing Holidays.txt file, overwriting the contents of the existing
 * file.
 *
 */

#include <stdlib.h>
#include <stdio.h>

enum InputEvent
{
	None   = 0x00,
	Print  = 0x01,
	Delete = 0x02,
	New    = 0x03,
	Change = 0x04,
	Quit   = 0x05,
};

int
HandleInput(int htable[100], int size);

int
GetHolidays(int htable[100]);

int
DateCompare(const void *x, const void *y);

int
RequestDateInput();

int *
FindDate(int htable[100], int size, int search);

void
PrintHolidays(int htable[100], int size);

void
OverwriteHoliday(int htable[100], int size);

void
ClearTable(int htable[100]);

int
main()
{
	int running = 1;
	int htable[100] = { 0 };
	int currentLength = GetHolidays(htable);
	while (running == 1)
	{
		int inputEvent = HandleInput(htable, currentLength);
		if (inputEvent == Quit)
		{
			running = 0;
		}
		else if (inputEvent == Delete || inputEvent == New || inputEvent == Change)
		{
			ClearTable(htable);
			currentLength = GetHolidays(htable);
		}
	}
	return 0;
}

int
HandleInput(int htable[100], int size)
{
	int result = None;
	char c;
	printf("Options:\n\t[p] display current holidays\n\t[d] delete a holiday from list\n\t[n] new holiday\n\t[c] change holiday\n\t[q] quit\n");
	scanf(" %c", &c);
	getchar();
	printf("input: %c\n", c);
	switch (tolower(c))
	{
		case 'p':
		{
			PrintHolidays(htable, size);
			result = Print;
		} break;

		case 'd':
		{
			int date = RequestDateInput();
			int *found = FindDate(htable, size, date);
			if (found) 
			{
				*found = 0;
				OverwriteHoliday(htable, size);
			}
			else
			{
				printf("warning: could not find requested holiday!\n");
			}
			result = Delete;
		} break;

		case 'n':
		{
			int date = RequestDateInput();
			result = New;
		} break;

		case 'c':
		{
			int date = RequestDateInput();
			result = Change;
		} break;

		case 'q':
		{
			result = Quit;
		} break;

		default:
		{
			result = None;
		} break;
	}
	return result;
}

int
GetHolidays(int htable[100])
{
	char *HolidayFile = "./data/holiday.txt";
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
	qsort(htable, i, sizeof(int), DateCompare);
	return i;
}

int
DateCompare(const void *x, const void *y)
{
	return ( *(int*)x - *(int*)y);
}

int
RequestDateInput()
{
	int month, day, year;
	printf("Enter a month, day, and year: ");
	scanf("%d %d %d", &month, &day, &year);
	return (year * 10000 + month * 100 + day);
}

int *
FindDate(int htable[100], int size, int search)
{
	return (int *)bsearch(&search, htable, size, sizeof(int), DateCompare);
}

void
PrintHolidays(int htable[100], int size)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		if (htable[i] == 0)
		{
			break;
		}
		printf("%d\n", htable[i]);
	}
}

void
OverwriteHoliday(int htable[100], int size)
{
	FILE *holidayFile;
	holidayFile = fopen("./data/holiday.txt", "w");
	char tempBuffer[64] = { 0 };
	if (holidayFile)
	{
		int i;
		for (i = 0; i < size; ++i)
		{
			if (htable[i] != 0)
			{
				int year = (htable[i] / 10000);
				int month = (htable[i] - (year * 10000)) / 100;
				int day = (htable[i] - (year * 10000)) - 100;
				sprintf(tempBuffer, "%d/%d/%d\n", month, day, year);
				fputs(tempBuffer, holidayFile);
			}
		}
	}
	fclose(holidayFile);
}


void
ClearTable(int htable[100])
{
	int i;
	for (i = 0; i < 100; ++i)
	{
		htable[i] = 0;
	}
}
