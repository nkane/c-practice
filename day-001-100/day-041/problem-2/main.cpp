/*
 * A child's parents promised to give the child $10 on her 12th birthday and double the gift
 * on every subsequent birthday until the gift exceeded $1000. Write a C program to determine
 * how old the girl will be when the last amount is given, and the total amount she received
 * including the last gift.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Start_Age = 12;
global_variable const int Start_Amount = 10;
global_variable const int Increment_Amount = 2;
global_variable const int Limit_Amount = 1000;

struct Person
{
	int Age;
	int IncrementAmount;
	int CurrentAmount;
};

inline Person
CreatePerson(int, int);

inline void
ComputeFinalP(Person *);

inline void
PrettyPrint(Person *);

int
main()
{
	Person P = CreatePerson(Start_Age, Increment_Amount);
	ComputeFinalP(&P);
	PrettyPrint(&P);

	return 0;
}

inline Person
CreatePerson(int age, int increment)
{
	Person P =
	{
		age,
		increment,
		0
	};

	return P;
}

inline void
ComputeFinalP(Person *p)
{
	int limit = 0;
	for (limit = Start_Amount; limit <= Limit_Amount; (limit *= p->IncrementAmount))
	{
		p->Age++;
		p->CurrentAmount += limit;
		PrettyPrint(p);
	}

	printf("-=-=-=-=-=-=-=-=-=-=-=-\n");

	p->CurrentAmount += limit;
}

inline void
PrettyPrint(Person *p)
{
	printf("Age: %d\n", p->Age);
	printf("Total: %d\n", p->CurrentAmount);
}
