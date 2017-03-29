/*
 * Write a C program that prompts theuser to input two numbers,
 * then swap the values stored in the two variables.
 */

#include <stdio.h>

#define len(x) (sizeof(x) / sizeof((x)[0]))

struct Numbers
{
	int X[2];
};

inline Numbers CreateNumbers();

inline void Swap(Numbers *);

inline void PrettyPrint(Numbers *);

int
main(void)
{
	Numbers N = CreateNumbers();
	Swap(&N);

	PrettyPrint(&N);

	return 0;
}

inline Numbers CreateNumbers()
{
	Numbers n =
	{
		{ 0, 0 },
	};

	int x = len(n.X);
	for (int i = 0; i < x; ++i)
	{
		printf("Enter in a value:\n");
		scanf("%d", n.X + i);
		printf("Value[%d] : %d\n", i, n.X[i]);
	}

	return n;
}

inline void Swap(Numbers *n)
{
	int temp = n->X[0];
	n->X[0] = n->X[1];
	n->X[1] = temp;
}

inline void PrettyPrint(Numbers *n)
{
	int x = len(n->X);
	for (int i = 0; i < x; ++i)
	{
		printf("Value[%d] : %d\n", i, n->X[i]);
	}
	
	scanf("%d", &x);
}
