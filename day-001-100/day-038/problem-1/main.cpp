/*
 * Write and run a C program that calculates and displays the amount of money available in
 * a bank account that initially has $1,000 deposited in it and earns 8 percent interest a year.
 * Your program should display the amount available at the end of each year for a period of
 * 10 years. Use the relationship that the money available at the end of each of year equals the
 * amount of money in the account at the start of the year plus .08 times the amount available
 * at the start of the year.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const float Initial_Amount = 1000.0f;
global_variable const float Interest_Rate = 0.08f;
global_variable const int Years = 10;

struct Account
{
	float Amount;
	float InterestRate;
};

inline Account
CreateAccount(float, float);

inline float
ComputeAmountWithInterestForYearA(Account *);

inline void
PrettyPrintA(Account *, int);

int
main()
{
	Account A = CreateAccount(Initial_Amount, Interest_Rate);
	PrettyPrintA(&A, 0);

	for (int i = 0; i < Years; ++i)
	{
		A.Amount = ComputeAmountWithInterestForYearA(&A);
		PrettyPrintA(&A, (i + 1));
	}

	return 0;
}

inline Account
CreateAccount(float amount, float interestRate)
{
	Account A = 
	{
		amount,
		interestRate,
	};

	return A;
}

inline float
ComputeAmountWithInterestForYearA(Account *a)
{
	float result = a->Amount;
	result += (a->Amount * a->InterestRate);
	return result;
}

inline void
PrettyPrintA(Account *a, int year)
{
	printf("Year: %d\n", year);
	printf("Account Amount: %.2f\n\n", a->Amount);
}

