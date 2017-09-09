/*
 * Write, compile, and execute a C program that calulcates and displays
 * the amount of money, A, available in N years when an initial deposit
 * of X dollars is deposited in a bank account paying for an annual interest
 * of R percent. Use the relationship that A = X * (1.0 + r / 100)^N. The program
 * should prompt the user to enter appropriate values and use scanf() statements
 * to accept the data. In constructing your prompts, use strings such as  ...
 * "Enter the amount of the inital deposit"
 * 
 * Verify the operation of your program by calculating, by hand, and using your
 * program, the amount of money available for the following test cases:
 * 
 * Test data set 1: $1000 invested for 10 years at 0% interest
 * Test data set 2: $1000 invested for 10 years at 6% interest
 */

#include <stdio.h>
#include <math.h>

#define compute_total_amount(currentAmount, interestRate, years) (currentAmount * pow((1.0f + interestRate / 100.0f), years)) 

struct Account
{
	float InitialAmount;
	float CurrentAmount;
	float InterestRate;
};

inline Account
CreateAccount();

inline void
ComputeTotalAmount(Account *, float);

inline void
PrettyPrint(Account *, float);

int
main(void)
{
	float years = 0.0f;
	Account A = CreateAccount();

	printf("Enter in the amount of years:\n");
	scanf("%f", &years);

	ComputeTotalAmount(&A, years);

	PrettyPrint(&A, years);

	return 0;
}

inline Account
CreateAccount()
{
	Account A = {};
	printf("Enter the amount of the inital deposit:\n");
	scanf("%f", &A.InitialAmount);

	A.CurrentAmount = A.InitialAmount;

	printf("Enter the interest rate (e.g., 6 = 6%):\n");
	scanf("%f", &A.InterestRate);


	return A;
}

inline void
ComputeTotalAmount(Account *account, float years)
{
	account->CurrentAmount = compute_total_amount(account->CurrentAmount, account->InterestRate, years);
}

inline void
PrettyPrint(Account * account, float years)
{
	printf("Account initial amount: %.2f\n", account->InitialAmount);
	printf("Account Interest Rate: %.2f\n", account->InterestRate);
	printf("Accoun years: %.2f\n", years);
	printf("Account Currenat Amount: %.2f\n", account->CurrentAmount);
}
