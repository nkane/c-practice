/*
 * Given an inital deposit of money, denoted as deposit, in a bank
 * that pays interest annually, the amount of money, amount, at a 
 * time n years later is given by the formula amount = deposit * (1 + i)^n
 * where i is the interest rate as a decimal number (for example, 9.5% is
 * .095) Using this formula, write, compile, and execute a C program that
 * determines the amount of money that will be availabe in four years if
 * $10,000 is deposited in a bank that pays 10% interest annually.
 */

#include <stdio.h>
#include <math.h>

struct BankAccount
{
	float InterestRate;
	float InitialAmount;
	float TotalAmount;
};

inline BankAccount
CreateBankAccount(float, float);

inline void
ComputeInterestOverYears(BankAccount *, float);

inline void
PrettyPrint(BankAccount *);

int
main(void)
{
	BankAccount B = CreateBankAccount(0.10f, 10000.0f);
	ComputeInterestOverYears(&B, 4.0f);
	PrettyPrint(&B);
	
	return 0;
}

inline BankAccount
CreateBankAccount(float interestRate, float initialAmount)
{
	return BankAccount
	{
		interestRate,
		initialAmount,
		initialAmount,
	};
}

inline void
ComputeInterestOverYears(BankAccount *account, float years)
{
	float result = 1.0f + account->InterestRate;
	result = pow(result, years);
	account->TotalAmount *= result;
}

inline void
PrettyPrint(BankAccount *b)
{
	printf("Bank Account inital Amount: %.2f\n", b->InitialAmount);
	printf("Bank Account Interest Rate: %.2f\n", b->InterestRate);
	printf("Bank Account Years: %d\n", 4);
	printf("Bank Account Total Amount: %.2f\n", b->TotalAmount);
}
