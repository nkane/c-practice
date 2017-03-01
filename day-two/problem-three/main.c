/*
 * The dollar change remaining after an amount paid is used to
 * a restaurant bill of amount check can be calculated using
 * the following C statements:
 * - determine the amount of pennies in the change
 * 	+ change = (paid - check) * 10
 * - determine the number of dollars in the change
 *  	+ dollars = change / 100
 * a) Using the previous statements as a starting point,
 *    write a C program that calculates the number of dollar
 *    bills, quarters, dimes, nickels, and pennies in the change
 *    when $10 is used to pay a bill of $6.07.
 * 
 * b) Determine the change when a check of $12.36 is paid
 *    using a $20 bill 
 */

#include <stdio.h>

#define BILL_ONE 6.07f
#define PAY_AMOUNT_ONE 10.00f

#define BILL_TWO 12.36f
#define PAY_AMOUNT_TWO 20.00f

int CalculateDollarBills(float, float);
int CalculateQuarters(int, int);

//void PrettyPrint(float, float, int, int, int, int);

int main(void)
{
	float billAmount, paidAmount = 0;
	int dollars, quarters, dimes, nickel = 0;
	
	billAmount = BILL_ONE;
	paidAmount = PAY_AMOUNT_ONE;

	dollars = CalculateDollarBills(billAmount, paidAmount);
	// NOTE(nick): billAmount needs to be adjusted
	billAmount = billAmount - (paidAmount - (float)dollars);

	return 0;
}

int CalculateDollarBills(float billAmount, float paidAmount)
{
	// paidAmount % billAmount
	// 10 % 6 -> 4
	int result = ((int)paidAmount % (int)billAmount);
	return result;
}

