/*
 * Write a program to simulate the roll of two dice. If the total of the two dice is 7 or 1
 * you win; otherwise, you lose. Embellish this program as much as you like, you betting,
 * different odds, different combinations for win or lose, stopping play when you have no
 * money left or reach the house limit, display the dice, etc.
 *
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define array_len(array)(sizeof(array)/sizeof(array[0]))
#define win(amount)(amount + amount)
#define lose(amount)(amount = (amount / 2.0f))

#define global_variable static

global_variable const float Start_Amount = 100.0f;
global_variable bool IsPlaying 		 = true;
global_variable const int Win_Min	 = 1;
global_variable const int Win_Max	 = 7;

int 
RollDice();

int
SumDice(int[], int);

int
main()
{
	float CurrentMoney = Start_Amount;
	float BetAmount = 0.0f;
	int DiceValues[2];
	char continueCheck = ' ';
	int sum;

	srand(time(NULL));

	while(CurrentMoney > 0.0f && IsPlaying)
	{
		printf("Enter in the amount to bet:\n");
		scanf("%f", &BetAmount);
		if (BetAmount > 0.0f && BetAmount <= CurrentMoney)
		{
			sum = 0;
			for (int i = 0; i < array_len(DiceValues); ++i)
			{
				DiceValues[i] = RollDice();
			}
			sum = SumDice(DiceValues, array_len(DiceValues));
			printf("........\n");
			printf("Rolled a %d\n", sum);
			if (sum == Win_Min || sum == Win_Max) 
			{
				printf("Congrats! you won!\n");
				CurrentMoney = win(CurrentMoney);
				printf("Current Money: %.2f\n", CurrentMoney);
			}
			else
			{
				printf("Sorry, you lost!\n");
				CurrentMoney = lose(CurrentMoney);
				printf("Current Money: %.2f\n", CurrentMoney);
			}
		}
		else
		{
			printf("Enter in a bet amount greater than $0.00 and less than $%.2f\n", CurrentMoney);
		}

		printf("Continue? (y/n)\n");
		scanf("\n%c", &continueCheck);

		if (tolower(continueCheck) != 'y')
		{
			IsPlaying = false;
		}
	}

	return 0;
}

int 
RollDice()
{
	int Result = 0;
	Result = (1 + (rand() % 7));
	return (Result);
}

int
SumDice(int array[], int size)
{
	int Result = 0;
	for (int i = 0; i < size; ++i)
	{
		Result += array[i];
	}
	return (Result);
}

