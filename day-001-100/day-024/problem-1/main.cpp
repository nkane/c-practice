/*
 * Write a C program to compute and display a person's weekly salary
 * as determined by the following specification:
 * - If the hours worked are less than or equal to 40, the person receives
 * $8.00 per hour; else the person receives $320.00 plus $12.00 for each
 * hour worked over 40 hours.
 * 
 * The program should request the hours worked as input and should display
 * the salary as output.
 */

#include <stdio.h>

#define WORK_WEEK_HOURS 40.0f
#define OVERTIME_RATE 12.0f
#define REGULAR_RATE 8.0f


struct Employee 
{
	float HoursWorked;
	float RegularPay;
	float OvertimePay;
};

inline Employee
CreateEmployee();

inline void
ComputeEmployeePay(Employee *);

inline void
PrettyPrint(Employee *);

int
main(void)
{
	Employee E = CreateEmployee();
	PrettyPrint(&E);

	return 0;
}

inline Employee
CreateEmployee()
{
	Employee E = {};

	printf("Enter in the number of hours worked:\n");
	scanf("%f", &E.HoursWorked);
	ComputeEmployeePay(&E);

	return E;
}

inline void
ComputeEmployeePay(Employee *e)
{
	e->RegularPay = (REGULAR_RATE * e->HoursWorked);

	if (e->HoursWorked > WORK_WEEK_HOURS)
	{
		// employee needs overtime
		// overtime hours = (hours worked - WORK_WEEK_HOURS)
		e->OvertimePay = (OVERTIME_RATE * (e->HoursWorked - WORK_WEEK_HOURS));
	}
}

inline void
PrettyPrint(Employee *e)
{
	printf("Employee hours worked: %.2f\n", e->HoursWorked);
	printf("Employee Regular Pay: %.2f\n", e->RegularPay);
	if (e->OvertimePay > 0)
	{
		printf("Employee Overtime Pay: %.2f\n", e->OvertimePay);
		printf("Employee Total Pay: %.2f\n", (e->RegularPay + e->OvertimePay));
	}
}
