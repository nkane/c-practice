/*
 * Create a file containing the following data:
 *
 * Name    		Rate    	Hours
 * Callaway, G.		6.00		40
 * Hanson, P.		5.00		48
 * Lasard, D.		6.50		35
 * Stillman, W.		8.00		50
 *
 * Write a C program that uses the information contained
 * in the file created to produce the follow pay report
 * for each employee:
 *
 * Name        Rate        Hours        Regular Pay        Overtime Pay        Gross Pay
 *
 * Any hours worked above 40 hours are paid at time and a half; additionally, the program
 * should display the total of the regular, overtime, and gross pay columns.
 *
 */

#include <stdio.h>

typedef struct _record
{
	char Name[20];
	float Rate;
	int Hours;
} Record;

int
main()
{
	FILE *readFile = NULL;

	if (readFile = fopen("./data/test.dat", "r"))
	{
		int overtimeHours = 0;
		float regularPay = 0.0f;
		float overtimePay = 0.0f;
		Record r = { 0 };
		while (fscanf(readFile, "%[^,],%f,%d ", r.Name, &r.Rate, &r.Hours) != EOF)
		{
			overtimeHours = 0;
			printf("Employee Name: %s\n", r.Name);	
			printf("Rate: %6.2f\n", r.Rate);
	
			if (r.Hours > 40)
			{
				overtimeHours = (r.Hours - 40);
				r.Hours -= overtimeHours;
			}

			printf("Regular Hours: %d\n", r.Hours);
			regularPay = (float)r.Hours * r.Rate;
			printf("Regular Pay: %6.2f\n", regularPay);

			if (overtimeHours > 0)
			{
				printf("Overtime Hours: %d\n", overtimeHours);
				overtimePay = ((float)overtimeHours * (r.Rate *= 1.5f));
				printf("Overtime Pay: %6.2f\n", overtimePay);
				printf("Total Pay: %6.2f\n", regularPay + overtimePay);
			}

			printf("\n");
		}
	}

	return 0;
}
