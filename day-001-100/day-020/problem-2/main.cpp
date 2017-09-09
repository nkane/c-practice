/*
 * Given a program, use #define statements where for appropriate literals
 * Example Program: 
 * 
 * ...
 * float prime, amount, interest;
 * prime = 0.08;
 * printf("Enter the amount:\n");
 * scanf("%f", &amount);
 * interest = prime * amount;
 * printf("The interest earned is %f dollars", interest);
 * return 0;
 * ...
 */

#include <stdio.h>

#define PRIME 0.08f
#define calculate_interest_earned(amount) (PRIME * amount)

struct Monies
{
	float Amount;
	float Interest;
};

inline Monies
CreateMonies();

inline void
CalculateMoniesInterest(Monies *);

int
main(void)
{
	Monies M = CreateMonies();
	CalculateMoniesInterest(&M);

	return 0;
}

inline Monies 
CreateMonies()
{
	Monies M =
	{
		0.0f,
		0.0f,
	};

	printf("Enter the amount:\n");
	scanf("%f", &M.Amount);

	return M;
}

inline void
CalculateMoniesInterest(Monies *m)
{
	m->Interest = calculate_interest_earned(m->Amount);
	printf("The interest earned is %.2f dollars\n", m->Amount);
}
