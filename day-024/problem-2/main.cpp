/*
 * A senior salesperson is paid $800 a week and junior salesperson $375
 * a week. Write a C program that accepts as input a salesperson's status
 * in a character variable. If the variable equals 's', the senior person's
 * salary should be displayed, else the junior persons salary should be output.
 */

#include <stdio.h>
#include <ctype.h>

#define SENIOR_SALARY 800.00f
#define JUNIOR_SALARY 375.00f

struct Employee
{
	char Position;
	float Salary;
};

inline Employee
CreateEmployee();

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
	printf("Enter employee position (e.g., 's' for senior or 'j' for junior):\n");
	scanf("%c", &E.Position);

	switch (tolower(E.Position))
	{
		case 's':
		{
			E.Salary = SENIOR_SALARY;
		} break;
		case 'j':
		{
			E.Salary = JUNIOR_SALARY;
		} break;
		default:
		{
			E.Salary = 0.0f;
		} break;
	}

	return E;
}

inline void
PrettyPrint(Employee *e)
{
	if (tolower(e->Position) == 's')
	{
		printf("Employee is a senior - salary is %.2f\n", e->Salary);
	}
	else if (tolower(e->Position == 'j'))
	{
		printf("Employee is a junior - salary is %.2f\n", e->Salary);
	}
	else 
	{
		printf("ERROR: An issue with input has occured!\n");
	}
}
