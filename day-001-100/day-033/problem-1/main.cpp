/*
 * Write a C program to prompt the user for a variable amount of inputs. In response to this prompt,
 * use this number to control the number of times a while loop is executed. Thus, if the user enters
 * 5 in the response to the prompt, the program should request the input of five numbers and display
 * the total after five numbers have been entered.
 */

#include <stdio.h>

int
main()
{
	int inputAmounts = 0;
	int i = 0;
	int requestAmount = 0;
	int sum = 0;

	printf("Enter the amount iterations:\n");
	scanf("%d", &inputAmounts);

	while (i < inputAmounts) 
	{
		printf("Enter amount (iteration #%d):\n", (i + 1));
		scanf("%d", &requestAmount);

		sum += requestAmount;

		requestAmount = 0;
		++i;
	}

	printf("Total Iterations: %d - Total Sum: %d\n", inputAmounts, sum);

	return 0;
}
