/*
 * Declare a single structure type suitable for an employee record consisting of an integer
 * indentification number, a last name (consisting of a maximum of 20 characters), a floating-point
 * pay rate, and a floating-point number of hours worked.
 *
 * Using the stucture type declared in the above, write a C program that interactively accepts the following
 * data into an array of six structures:
 *
 * id number        name            pay rate        hours worked
 * --------         ----            -------         ------------
 * 3462             Jones           4.62            40.0
 * 6793             Robbins         5.83            38.5
 * 6985             Smith           5.22            45.5
 * 7834             Swain           6.89            40.0
 * 8867             Timmins         6.43            35.5
 * 9002             Williams        4.75            42.0
 *
 * Once the data has been entered, the program should create a payroll report listing each employee's name,
 * number, and gross pay. Inlcude the total gross pay of all employees at the end of the report.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

typedef struct _employee
{
    int id;
    char name[20];
    float payRate;
    float hoursWorked;
    float grossPay;
} Employee;

Employee
GetEmployeeInfo();

void
PrintEmployeeReport(Employee *e, int size);

int
main()
{
    Employee data[6] = { 0 };
    int i;

    for (i = 0; i < len(data) - 5; ++i)
    {
        *(data + i) =  GetEmployeeInfo();
    }

    PrintEmployeeReport(data, len(data));

    return 0;
}

Employee
GetEmployeeInfo()
{
    Employee result = { 0 };

    printf("id: ");
    scanf("%d", &result.id);

    printf("name: ");
    scanf("%s", &result.name);

    printf("pay rate: ");
    scanf("%f", &result.payRate);

    printf("hours worked: ");
    scanf("%f", &result.hoursWorked);

    result.grossPay = (result.payRate * result.hoursWorked);

    return result;
}

void
PrintEmployeeReport(Employee *e, int size)
{
    int i;
    printf("===================================\n");
    for (i = 0; i < size; ++i)
    {
        printf("id : %d\nname: %s\npay rate: %6.2f\nhours worked; %6.2f\ngross pay: %6.2f\n===================================\n",
                (e + i)->id, (e + i)->name, (e + i)->payRate, (e + i)->hoursWorked, (e + i)->grossPay);
    }
}

