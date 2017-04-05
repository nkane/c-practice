/*
 * If money is left in a particular bank for more than five years,
 * the interest rate given by the bank is 7.5 percent, else the interest
 * rate is 5.4 percent. Write a C program that uses the scanf() function to
 * accept the number of years into a variable and display the appropriate 
 * rate depending on the value input into the variable.
 */

#include <stdio.h>

#define HIGH_INTEREST_YEARS 5

#define HIGH_INTEREST_RATE 7.5f
#define LOW_INTEREST_RATE 5.4f

struct Account 
{
	float InitialAmount;
	float CurrentAmount;
	float CurrentInterestRate;
	float YearsOpen;
};

inline Account
CreateAccount();

inline void
ComputeAccountInterestRate(Account *);

inline void
PrettyPrint(Account *);

int
main(void)
{
	Account A = CreateAccount();
	ComputeAccountInterestRate(&A);
	PrettyPrint(&A);
	
	return 0;
}

inline Account
CreateAccount()
{
	Account A = {};
	printf("Enter in number of years the account has been opened:\n");
	scanf("%f", &A.YearsOpen);
	return A;
}

inline void
ComputeAccountInterestRate(Account *a)
{
	a->CurrentInterestRate = LOW_INTEREST_RATE;
	if (a->YearsOpen >= HIGH_INTEREST_YEARS)
	{
		a->CurrentInterestRate = HIGH_INTEREST_RATE;
	}
}

inline void
PrettyPrint(Account *a)
{
	printf("Account years: %.2f\n", a->YearsOpen);
	printf("Account interest rate: %.2f\n", a->CurrentInterestRate);
}
