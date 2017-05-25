/*
 * A common statistical problem is to determin how many ways n objects can be
 * selected from a group of m objects. The number of such possibilities is given by
 * the formula:
 *
 * m! / n! (m - n)!
 *
 * m = 8
 * n = 3
 *
 * (8 * 7 * 6 * 5 * 4 * 3 * 2 * 1) / (3 * 2 * 1) (5 * 4 * 3 * 2 * 1) = ~56
 *
 */

#include <stdio.h>

inline float
MultiplyNTimes(float);

int
main()
{
	float n = 0.0f, m = 0.0f;

	printf("Enter in a value for n:\n");
	scanf("%f", &n);

	printf("Enter in a value for m:\n");
	scanf("%f", &m);

	float topResult = MultiplyNTimes(m);
	float bottomResult = (MultiplyNTimes(n) * MultiplyNTimes((m - n)));
	float result = topResult / bottomResult;

	printf("Result: %.2f\n", result);

	return 0;
}

inline float
MultiplyNTimes(float n)
{
	if (n > 0)
	{ 
		return n * MultiplyNTimes(n - 1);
	}

	return 1;
}

