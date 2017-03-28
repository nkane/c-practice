/*
 * Write a C program that displays the following prompts:
 * "Enter a number:"
 * "Enter a second number:"
 * "Enter a third number:"
 * "Enter a fourth number:"
 *
 * After the prompt is displayed, your program should use a scanf()
 * function call to accept a number from the keyboard for the displayed
 * prompt. After the fourth number has been entered, your program should
 * calculate and display the average of the numbers. The average should
 * be included in an appropriate message.
 */

#include <stdio.h>

struct Numbers
{
	float x[4];
};

inline Numbers
CreateNumbers();

inline float
ComputeNumbersAverage(Numbers *);

inline void 
PrettyPrint(float);

int
main(void)
{
	Numbers N = CreateNumbers();
	float average = ComputeNumbersAverage(&N);
	PrettyPrint(average);

	return 0;
}

inline Numbers
CreateNumbers()
{
	Numbers N =
	{
		{ 0.0f, 0.0f, 0.0f, 0.0f },
	};

	for (int i = 0; i < 4; ++i)
	{
		printf("Enter a number-%d:\n", i + 1);
		scanf("%f", &N.x[i]);
	}

	return N;
}

inline float
ComputeNumbersAverage(Numbers *n)
{
	float result = 0.0f;

	for (int i = 0; i < 4; i++)
	{
		result += n->x[i];
	}

	result /= 4.0f;

	return result;
}

inline void 
PrettyPrint(float result)
{
	int x = 0;
	printf("Average of numbers: %.2f\n", result);
	scanf("%d", &x);
}
