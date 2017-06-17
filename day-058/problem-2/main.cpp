/*
 * Create a C program that flips a coin randomly and requests the number
 * of coin tosses. Print out the percetnages of heads and tails obtained
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

inline float
ComputePercentage(float, float);

int
main()
{
	int flips = 0;
	int HeadsCount = 0;
	int TailsCount = 0;

	printf("How many tosses?\n");
	scanf("%d", &flips);

	if (flips > 0)
	{
		time_t t;
		srand((unsigned int)time(&t));
		for (int i = 0; i < flips; ++i)
		{
			if ((rand() % 50) > 25)
			{
				++HeadsCount;
			}
			else
			{
				++TailsCount;
			}
		}

		printf("Heads Percentange: %2.f\n", ComputePercentage((float)flips, (float)HeadsCount));
		printf("Tails Percentange: %2.f\n", ComputePercentage((float)flips, (float)TailsCount));
	}

	return 0;
}

inline float
ComputePercentage(float base, float amounts)
{
	float result = 0.0f;
	result = (amounts / base) * 100.0f;
	return result;
}

