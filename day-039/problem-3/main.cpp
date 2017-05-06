/*
 * Modify the program created in problem 2 - it should display the average of the positive
 * and negative numbers (hint: Be careful not to count the number 0 as a negative number). 
 * Test your program by entering the numbers 17, -10, 20, 0, and -4. The positive average
 * displayed by your program should be 18.5 and the negative average, -7.
 *
 */

#include <stdio.h>

#define Average(x, y) (x / y)


/// all the numbers sumed / total numbers

int
main()
{
	float positiveSum = 0.0f,
	      negativeSum = 0.0f;

	int loopAmount = 0;
	int positiveNums = 0;
	int negativeNums = 0; 

	float currentAmount = 0.0f;

	printf("Enter in the loop amount:\n");
	scanf("%d", &loopAmount);

	for (int i = 0; i < loopAmount; ++i)
	{
		printf("Enter in an amount:\n");
		scanf("%f", &currentAmount);


		if (currentAmount > 0)
		{
			positiveSum += currentAmount;
			positiveNums++;
		}
		else if (currentAmount < 0)
		{
			negativeSum += currentAmount;
			negativeNums++;
		}
	}

	printf("Positive Average: %.2f\n", Average(positiveSum, positiveNums));
	printf("Negative Average: %.2f\n", Average(negativeSum, negativeNums));

	return 0;
}

