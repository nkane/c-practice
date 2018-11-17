/*
 * Create a file containing the following names, social security numbers,
 * hourly rate, and hours worked:
 *
 *	+----------------+---------------+--------+----+
 *	|  B. Clandwell  |  XXX-XX-XXXX  |  7.32  | 37 |
 *	+----------------+---------------+--------+----+
 *	|  D. Memcheck   |  XXX-XX-XXXX  |  8.32  | 40 |
 *	+----------------+---------------+--------+----+
 *	|  R. Potter     |  XXX-XX-XXXX  |  6.54  | 40 |
 *	+----------------+---------------+--------+----+
 *	|  W. Rosen      |  XXX-XX-XXXX  |  9.80  | 35 |
 *	+----------------+---------------+--------+----+
 * 
 * Write a C program that reads the data file created above, and computes
 * and displays a payroll schedule. The output should list the social security
 * number, name, and gross pay for each individual.
 *
 */

#include <stdio.h>
#include <string.h>

typedef struct _record
{
	char Name[25];
	char SocialNumber[16];
	float HourlyRate;
	int HoursWorked;
	float GrossPay;
} Record;

int
main()
{
	FILE *dataFile = NULL;
	dataFile = fopen("./data/test.dat", "r");;

	if (dataFile)
	{
		Record r = { 0 };
		while (fscanf(dataFile, "%[^,],%[^,],%f,%d ", r.Name, r.SocialNumber, &r.HourlyRate, &r.HoursWorked) != EOF)
		{
			r.GrossPay = ((float)r.HoursWorked * r.HourlyRate);
			printf("Name: %s\n", r.Name);
			printf("Social Number: %s\n", r.SocialNumber);
			printf("Hourly Rate: %6.2f\n", r.HourlyRate);
			printf("Hours Worked: %d\n", r.HoursWorked);
			printf("Gross Pay: %6.2f\n\n", r.GrossPay);
			memset(r.Name, 0, 25);
			memset(r.SocialNumber, 0, 16);
			r.HoursWorked = 0;
			r.HourlyRate = 0.0f;
			r.GrossPay = 0.0f;
		}
		fclose(dataFile);
	}

	return 0;
}
