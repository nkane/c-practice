/*
 * The dollar change remaining after an amount paid is used to
 * a restaurant bill of amount check can be calculated using
 * the following C statements:
 * - determine the amount of pennies in the change
 * 	+ change = (paid - check) * 100
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
#include <math.h>

#define BILL_AMOUNT_ONE 6.07f
#define PAID_AMOUNT_ONE 10.00f

#define BILL_AMOUNT_TWO 12.36f
#define PAID_AMOUNT_TWO 20.00f

inline int CalculateTotalChangeInPennies(float, float);

inline int CalculateTotalCoinAmount(int, int);

inline int AdjustRemainingAmount(int, int, int);

inline void PrettyPrint(int, int, int, int, int);

int main(void)
{
	int changeInPennies = CalculateTotalChangeInPennies(PAID_AMOUNT_ONE, BILL_AMOUNT_ONE);
	int dollarBills = (changeInPennies / 100);

	int remainingChange = AdjustRemainingAmount(changeInPennies, 100, dollarBills);

	int quarters = CalculateTotalCoinAmount(remainingChange, 25);
	remainingChange = AdjustRemainingAmount(remainingChange, 25, quarters);
	
	int dimes = CalculateTotalCoinAmount(remainingChange, 10);
	remainingChange = AdjustRemainingAmount(remainingChange, 10, dimes);

	int nickels = CalculateTotalCoinAmount(remainingChange, 5);
	remainingChange = AdjustRemainingAmount(remainingChange, 5, nickels);

	int pennies = CalculateTotalCoinAmount(remainingChange, 1);
	remainingChange = AdjustRemainingAmount(remainingChange, 1, pennies);

	// NOTE: print the first bill info
	PrettyPrint(dollarBills, quarters, dimes, nickels, pennies);

	changeInPennies = CalculateTotalChangeInPennies(PAID_AMOUNT_TWO, BILL_AMOUNT_TWO);

	dollarBills = (changeInPennies / 100);
	remainingChange = AdjustRemainingAmount(changeInPennies, 100, dollarBills);
	
	quarters = CalculateTotalCoinAmount(remainingChange, 25);
	remainingChange = AdjustRemainingAmount(remainingChange, 25, quarters);

	dimes = CalculateTotalCoinAmount(remainingChange, 10);
	remainingChange = AdjustRemainingAmount(remainingChange, 10, dimes);
	
	nickels = CalculateTotalCoinAmount(remainingChange, 5);
	remainingChange = AdjustRemainingAmount(remainingChange, 5, nickels);

	pennies = CalculateTotalCoinAmount(remainingChange, 1);
	remainingChange = AdjustRemainingAmount(remainingChange, 1, pennies);

	// NOTE: print the second bill info
	PrettyPrint(dollarBills, quarters, dimes, nickels, pennies);

	return 0;
}

inline int CalculateTotalChangeInPennies(float paidAmount, float billAmount)
{
	int result = roundf((paidAmount - billAmount) * 100.00f);
	return result;
}

inline int CalculateTotalCoinAmount(int remainingBill, int coinAmount)
{
	int result = (remainingBill / coinAmount);
	return result;
}

inline int AdjustRemainingAmount(int remainingAmount, int coinAmount, int amountOfCoin)
{
	int result = (remainingAmount - (amountOfCoin * coinAmount));
	return result;
}

inline void PrettyPrint(int dollarBills, int quarters, int dimes, int nickels, int pennies)
{
	printf("=================================================\n");
	printf("Dollar Bills: %d\n", dollarBills);
	printf("Quarters: %d\n", quarters);
	printf("Dimes: %d\n", dimes);
	printf("Nickels: %d\n", nickels);
	printf("Pennies: %d\n", pennies);
	printf("=================================================\n");
}
