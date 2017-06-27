/*
 *
 * Here is a version of a problem called "the random walk." It can be extended to two or
 * three dimensions, and used to simulate molecular motion, to determine the effectiveness
 * of reactor shielding, or to calculate a variety of other probabilities.
 *
 * Assume that your very tired and sleepy dog leaves his favorite lamppost on a warm 
 * summer evenings and staggers randomly either two steps in the direction toward home
 * or one step in the opposite direction. After taking these steps, the dog again staggers, 
 * randomly two steps toward home or one step backward, and does this again, and again. If
 * the pet reaches a total distance of 10 steps from the lamppost in the direction toward
 * home, you find him and take him home. If the dog arrives back at the lamppost before
 * reaching 10 steps in the direction towards home, he lies down and spend the night at the
 * foot of the lamppost.
 *
 * Write a C program that simulates 500 summer evenings, and calculates and print the percentage
 * of the time your pet sleeps at home for these evenings. (Hint: In a loop determine forward
 * or backward based on the value of a random number.) Accumulate the distance the dog has reached
 * toward your home. If the distance reaches 10, stop the loop and increment the home count. If the
 * distance reaches 0 before it reaches 10, stop the loop but do not increment the home count. Repeat
 * this loop 500 times and find the ratio of (home count)/500.0.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define global_variable static

global_variable const int Forward_Step  = 2;
global_variable const int Backward_Step = 1;
global_variable const int Finish_Steps  = 10;
global_variable const int Total_Simulations = 500;

global_variable bool Simulating = true;

int
GenerateNumber();

bool
IsForward(int);

bool
IsCloseToHome(int);

int
main()
{
	int randomNumber = 0;
	int moveCount = 0;
	int currentSteps = 0;
	int homeCount = 0;

	srand(time(NULL));

	for (int i = 0; i < 500; ++i)
	{
		Simulating = true;
		moveCount = 0;
		currentSteps = 0;
		while (Simulating)
		{
			randomNumber = GenerateNumber();
			if (IsForward(randomNumber))
			{
				// two steps forward
				currentSteps += Forward_Step;
			}
			else
			{
				// one step backward
				currentSteps -= Backward_Step;
			}

			if (IsCloseToHome(currentSteps))
			{
				// yay - goes home
				++homeCount;
				Simulating = false;
			}
			else if ((currentSteps == 0) || (moveCount > Finish_Steps && currentSteps <= 0))
			{
				// end simulation
				Simulating = false;
			}
			++moveCount;
		}
	}

	printf("Sleeps at home %.2f%c", (((float)homeCount/(float)Total_Simulations) * 100.0f), '%');
	
	return 0;
}

int
GenerateNumber()
{
	int result;
	result = (1 + (rand() % 10));
	return (result);
}

bool
IsForward(int randomNumber)
{
	bool result = (randomNumber >= 5) ? true : false;
	return (result);
}

bool
IsCloseToHome(int stepCount)
{
	bool result = (stepCount >= Finish_Steps) ? true : false;
	return (result);
}

