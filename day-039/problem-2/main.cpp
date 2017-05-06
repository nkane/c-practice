/*
 * Write a C program that accepts a variable amount of numbers to be entered for how
 * many times the program computes the positive and negative sums of a set for numbers
 * that are requested in the loop.
 *
 */

#include <stdio.h>


inline int
RequestNumber();

inline void
Print(float, float);

int
main()
{
	float positiveSum = 0.0f,
	      negativeSum = 0.0f;

	int x = 0;
	printf("Enter in a loop amount:\n");
	scanf("%d", &x);

	int currentNumber = 0;

	for (int i = 0; i < x; ++i)
	{
		currentNumber = RequestNumber();
		if (currentNumber >= 0)
		{
			positiveSum += currentNumber;
		}
		else
		{
			negativeSum += currentNumber;
		}
	}

	Print(positiveSum, negativeSum);

	return 0;
}


inline int
RequestNumber()
{
	int result = 0;
	printf("Enter in a number (positive or negative):\n");
	scanf("%d", &result);
	return result;
}

inline void
Print(float x, float y)
{
	printf("Positive: %f\n", x);
	printf("Negative: %f\n", y);
}

