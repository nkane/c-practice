/*
 * Write a main() program that first ask the user for an integer, N, 
 * and then calculates three sums: the sum of the even integers, the
 * sume of the odd itnegers, and the sum of all integers 0 to N; however,
 * excluded from these sums are the integers that are divisible by 3
 * or divisible by 4. 
 *
 */

#include <stdio.h>

int
main()
{
	int loopAmount = 0;
	int totalSum = 0;
	int evenSum = 0;
	int oddSum = 0;

	printf("Enter N: ");
	scanf("%d", &loopAmount);

	for (int i = 0; i <= loopAmount; ++i)
	{
		if ((i % 3) == 0)
		{
			continue;
		}
		else if ((i % 4) == 0)
		{
			continue;
		}
		else
		{
			if ((i % 2) == 0)
			{
				evenSum += i;
			}
			else 
			{
				oddSum += i;
			}

			totalSum += i;
		}
	}

	printf("Total sum: %d\n", totalSum);
	printf("Even sum: %d\n", evenSum);
	printf("Odd sum: %d\n", oddSum);

	return 0;
}
