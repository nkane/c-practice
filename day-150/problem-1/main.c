/*
 * Enter and execute Program 13.1
 *
 */

#include <stdio.h>

typedef struct _test
{
    int idNum;
    double *ptPay;
} Test;

int
main()
{
    Test emp;
    double pay = 456.20;

    emp.idNum = 12345;
    emp.ptPay = &pay;

    printf("Employee number %d was paid %6.2f\n", emp.idNum, *emp.ptPay);

    pay += 100.00;
    printf("Employee number %d was paid %6.2f\n", emp.idNum, *emp.ptPay);

    return 0;
}
