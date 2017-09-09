/*
 * Write a program that tests the effectiveness of the rand() function provided by
 * your compiler. Start by initializing 10 counters, such as onescount, twoscount to
 * tenscount, all to 0. Then generate a large number of random integers between 1 and
 * 10. Each time 1 occures, increment onescount; when a 2 occurs, increment twoscount;
 * etc. Finally, printf out the number of 1s, 2s, etc. that occur and the percentage
 * of the time each number occured.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define array_len(array) (sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable int Counts[10] = { 0 };

inline void
GenerateRandomNumberData(int, int[]);

inline void
Print(int[], int, int);

int
main()
{
	int iterations = 0, randomNumber   = 0;
	srand(time(NULL));

	printf("Enter in the number of iterations:\n");
	scanf("%d", &iterations);

	GenerateRandomNumberData(iterations, Counts);
	Print(Counts, array_len(Counts), iterations);

	system("pause");

	return 0;
}

inline void
GenerateRandomNumberData(int iterations, int array[])
{
	int randomNumber = 0;
	for (int i = 0; i < iterations; ++i)
	{
		// random number between 1 and 10
		randomNumber = (1 + (rand() % 10));
		array[randomNumber - 1]++;
	}
}

inline void
Print(int array[], int size, int iterations)
{
	float average = 0.0f;
	for (int i = 0; i < size; ++i)
	{
		average = (((float)array[i] / (float)iterations) * 100.0f);
		printf("Number %d - Value: %d - Average: %.2f%c\n", (i + 1), array[i], average, '%');
	}
}

