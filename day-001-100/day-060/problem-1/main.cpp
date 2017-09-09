/*
 * Write a C program to create a HI-LO game. In this game the computer produces a
 * random integer between 1 and 100 and provides the user with seven tries to guess
 * the generated number. If the user guesses the correct number, the message "Hooray,
 * you have won!" should be displayed. After each incorrect guess, the computer should
 * display the message, "Wrong Number, Try Again" and indicates whether the guess was
 * too high or too low and display the number of guesses left. After seven incorrect
 * guesses, the computer should display the message, "Sorry, you lose" and the correct
 * number.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define global_variable static

global_variable const int Attempts = 7;
global_variable const int Min 	   = 1;
global_variable const int Max	   = 100;

bool
GuessLoop(int, int);

int
main()
{
	int generatedNumber = 0;

	srand(time(NULL));

	// generate a number between 1 and 100
	// 100 % 100 = 0 + 1 = 1
	// 100 % 99  = 1 + 1 = 2
	generatedNumber = Min + (rand() % Max);
	printf("Random number generated!\n");
	if (GuessLoop(generatedNumber, Attempts))
	{
		printf("Horray, you have won! :)\n");
	}
	else
	{
		printf("Sorry, you lose :(\n");
		printf("value was: %d\n", generatedNumber);
	}

	system("pause");

	return 0;
}

bool
GuessLoop(int guessValue, int attemps)
{
	int userGuess = 0;
	for (int i = 0; i < attemps; ++i)
	{
		printf("Attempt Remaining [%d]\n", (attemps - i));
		printf("Enter in a guess:\n");
		scanf("%d", &userGuess);
		if (userGuess == guessValue)
		{
			return true;
		}
		else
		{
			if (userGuess > guessValue)
			{
				printf("value entered too HIGH!\n");
			}
			else
			{
				printf("value entered too LOW!\n");
			}
		}
	}
	return false;
}

