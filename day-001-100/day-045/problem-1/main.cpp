/*
 * Write a C program that calculates and displays the yearly amount available if $1000 is
 * invested in a bank account for 10 years. Your program should display the amounts available
 * for interest rates from 6 percent to 12 percent inclusively, at 1 percent increments.
 * Use a nested loop, with the outter loop having a fixed count of 7 and the inner loop a
 * fixed count of 10. The first iteration of the outer loop should use an interest rate of
 * 6 percent and display the amount of money available at the end of the first 10 years. In
 * each subsequent pass through the outer loop, the interest rate should be increased by 1
 * percent. Use the relationship that the money available at the end of each yearh equals
 * the amount of money in the account at the start of the year plus the interest rate times
 * the amount available at the start of the year.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define global_variable static

global_variable const float Initial_Amount = 1000.0f;
global_variable const int Start_Rate     = 6;
global_variable const int Max_Rate 	 = 12;
global_variable const int Increment_Rate = 1;
global_variable const int Start_Year     = 1;
global_variable const int Max_Year 	 = 10;

struct Account
{
	float InitialAmount;
	float CurrentAmount;
	int Years;
};

inline Account *
CreateAccount(float, int);

inline void
ReleaseAccount(Account *);

inline void
AccountReset(Account *);

inline float
ComputeAccountAmount(Account *, float);

int
main()
{
	Account *A = CreateAccount(Initial_Amount, Start_Year);

	for (int currentRate = Start_Rate; currentRate <= Max_Rate; currentRate += Increment_Rate)
	{
		printf("------Rate %d percent -------\n", currentRate);
		while (A->Years <= Max_Year)
		{
			A->CurrentAmount = ComputeAccountAmount(A, (float)currentRate);
			printf("Year %d - Amount: %.2f\n", A->Years, A->CurrentAmount);
			++A->Years;
		}

		AccountReset(A);
		printf("\n\n");
	}

	ReleaseAccount(A);

	return 0;
}

inline Account*
CreateAccount(float amount, int year)
{
	Account *A = (Account *)malloc(sizeof(Account));
	A->CurrentAmount = amount;
	A->InitialAmount = amount;
	A->Years = year;
	return A;
}

inline void
ReleaseAccount(Account *a)
{
	if (a)
	{
		free(a);
	}
}

inline void
AccountReset(Account *a)
{
	a->CurrentAmount = a->InitialAmount;
	a->Years = 0;
}

inline float
ComputeAccountAmount(Account *a, float rate)
{
	float result = a->CurrentAmount;
	result += (a->CurrentAmount * rate / 100.0f);
	return result;
}

