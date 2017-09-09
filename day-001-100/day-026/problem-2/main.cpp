/*
 * The interest rate used on funds deposited in a bank is determined by the
 * amount of time the money is left on deposit. For a particular bank, the 
 * following schedule is used. Write a C proram that accepts the time that
 * funds are left on deposit and displays the interest rate corresponding to
 * the time entered.
 *
 * Time on Deposit	| Interest Rate
 * > 5	 		  0.045
 * < 5 && >= 4		  0.040
 * < 4 && >= 3		  0.035
 * < 3 && >= 2		  0.030
 * < 2 && >= 1		  0.025
 * < 1			  0.020
 */

#include <stdio.h>

const float InterestRates [] = { 0.020f, 0.025f, 0.030f, 0.035f, 0.040f, 0.045f };

struct Account
{
	int years;
	float interest_rate;
};

inline Account
CreateAccount();

inline float
DetermineInterestRate(Account *);

inline void
PrettyPrint(Account *);

int
main()
{
	Account A = CreateAccount();
	PrettyPrint(&A);

	return 0;
}

inline Account
CreateAccount()
{
	Account A = {};
	printf("Enter the time that funds have been left of deposit:\n");
	scanf("%d", &A.years);
	
	A.interest_rate = DetermineInterestRate(&A);

	return A;
}

inline float
DetermineInterestRate(Account *a)
{
	float result;
	unsigned int index;

	if (a->years < 0)
	{
		index = 0;
	}
	else if (a->years > 5)
	{
		index = 5;
	}
	else 
	{
		index = (a->years - 1);
	}

	result = InterestRates[index];

	return result;
}

inline void
PrettyPrint(Account *a)
{
	printf("Account years: %d\n", a->years);
	printf("Account interest rate: %.2f\n", a->interest_rate);
}
