/*
 * Create a file containing the following data:
 *
 *	+-------------+-------------------+----------+----+
 *	|   H. Baker  |  614 Freeman St.  |  Orange  | NJ |
 *	+-------------+-------------------+----------+----+
 * 	|   D. Rosso  |  83 Chambers St.  |  Madison | NJ |
 * 	+-------------+-------------------+----------+----+
 * 	|    K.Tims   | 890 Ridgewood Rd. | Millburn | NJ |
 * 	+-------------+-------------------+----------+----+	
 * 	| B. Williams |  24 Tremont Ave.  | Brooklyn | NY |
 * 	+-------------+-------------------+----------+----+ 
 *
 * Write a program to read and display the data file created using the
 * following output format:
 *
 * 	Name:
 * 	Address:
 * 	City, State:
 *
 */

#include <stdio.h>

// NOTE(nick): was going to use a linked list, but decided not to :)
//#include "list.c"

typedef struct _record
{
	char Name[20];
	char AddressLine[20];
	char City[20];
	char State[2];
} Record;

void
ReadDataFile(FILE *file);

void
ReadCSVLine(char *stringBuffer, Record *record);

int
main()
{
	FILE *dataFile = fopen("./data/test.dat", "r");
	if (dataFile)
	{
		ReadDataFile(dataFile);
		fclose(dataFile);
	}
	return 0;
}

void
ReadDataFile(FILE *file)
{
	Record result = { 0 };
	char lineBuffer[256] = { 0 };
	while (fgets(lineBuffer, sizeof(lineBuffer), file))
	{
		ReadCSVLine(lineBuffer, &result);
		printf("Name: %s\n", result.Name);
		printf("Address: %s\n", result.AddressLine);
		printf("City, State: %s, %s\n", result.City, result.State);
	}
}

void
ReadCSVLine(char *stringBuffer, Record *record)
{
	int i = 0;
	int j = 0;
	int columnCVS = 0;
	while (*(stringBuffer + i) != '\0' && *(stringBuffer + i) != '\n')
	{
		if (*(stringBuffer + i) == ',')
		{
			++columnCVS;
			j = 0;
		}
		else
		{
			switch (columnCVS)
			{
				case 0:
				{
					*(record->Name + j) = *(stringBuffer + i);
				} break;

				case 1:
				{
					*(record->AddressLine + j) = *(stringBuffer + i);
				} break;

				case 2:
				{
					*(record->City + j) = *(stringBuffer + i);
				} break;

				case 3:
				{
					*(record->State + j) = *(stringBuffer + i);
				}
			}
			++j;
		}
		++i;
	}
}
