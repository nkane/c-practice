/*
 * Create file named employee.dat containing the following data:
 *
 * 	+---------+------+-------+-------+----------+
 * 	| Anthony | A.J. | 10031 |  7.82 | 12/18/62 |
 * 	+---------+------+-------+-------+----------+
 * 	| Burrows | W.K. | 10067 |  9.14 |  6/9/63  |
 * 	+---------+------+-------+-------+----------+
 * 	|   Fain  | B.D. | 10083 |  8.74 |  5/18/59 |
 * 	+---------+------+-------+-------+----------+
 * 	|  Janney |  P.  | 10095 | 10.57 |  9/28/62 |
 * 	+---------+------+-------+-------+----------+
 * 	|  Smith  | G.J. | 10105 |  8.50 | 12/20/61 |
 * 	+---------+------+-------+-------+----------+ 
 *
 * Write a program called fcopy to read the employee.dat and produce a duplicate copy of the
 * file named employee.dat.bak
 *
 * Modify the program to accept the name of the original and duplicate file as user input.
 *
 * Since fcopy always copies data from an original file to a duplicate file, can you think
 * of a better method of accepting the original and duplicate filenames than prompting the
 * user for them each time the program is executed?
 *
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct _record
{
	char *Name;
	char *Code;
	int ID;
	float Rate;
	char *Date;
} Record;

FILE *
OpenEmployeeFile();

void 
FCopy(FILE *file, char *newFileName);

int
main()
{
	FILE *employeeFile = NULL;
	char stringBuffer[256] = { 0 };
	char *employeeFileName = "employee";
	char inputValue = ' ';
	employeeFile = OpenEmployeeFile("r");

	printf("Enter in custom name? (y/n)");
	scanf("\n%c", &inputValue);

	if (tolower(inputValue) == 'y')
	{
		printf("Enter in name: ");
		gets(stringBuffer);
		FCopy(employeeFile, stringBuffer);
	}
	else
	{
		FCopy(employeeFile, employeeFileName);
	}

	if (employeeFile)
	{
		fclose(employeeFile);
	}

	return 0;
}

FILE *
OpenEmployeeFile(char *filePermissions)
{
	const char *fileLocation = "./data/employee.dat";
	FILE *result = fopen(fileLocation, filePermissions);
	if (result == NULL)
	{
		printf("ERROR: cannot open file %s\n", fileLocation);
	}
	return (result);
}

void 
FCopy(FILE *file, char *newFileName)
{
	char stringBuffer[256] = { 0 };
	const char *backupFileLocation = "./data/";
	strcat(stringBuffer, backupFileLocation);
	strcat(stringBuffer, newFileName);

	char timeBuffer[26] = { 0 };
	time_t rawTime;
	struct tm *timeInfo;
	time(&rawTime);
	timeInfo = localtime(&rawTime);
	sprintf(timeBuffer, "-%d-%d-%d-%d-%d-%d", (timeInfo->tm_year + 1990), timeInfo->tm_mon, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
	strcat(stringBuffer, timeBuffer);
	strcat(stringBuffer, ".bak");
	
	FILE *newFile = fopen(stringBuffer, "a+");

	if (newFile)
	{
		char lineBuffer[256];
		// TODO(nick): finish this up ...
		while (fgets(lineBuffer, 256, file) != NULL)
		{
			fputs(lineBuffer, newFile);
		}
		fclose(newFile);
	}
	else
	{
		printf("ERROR: failed to create file %s\n", stringBuffer);
	}
}

