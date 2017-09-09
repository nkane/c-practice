/*
 * In the game of blackjack, the cards 2 through 10 are counted at their face values, regardless
 * of suit, all picture cards (jack, queen, and king) are counted as 10, and an ace is
 * counted as either a 1 or an 11, depending on the total count of all the cards in a player's
 * hand. The ace is counted as 11 only if the total value of all cards in a player's hand does
 * not exceed 21, else it is counted as a 1. Using this information write a C program that uses
 * a random number generator to select three cards (a 1 initially corresponding to an ace,
 * a 2 corresponding to a face card of two, and so on), calculate the total value of the 
 * hand appropriately, and display the value of the three cards with a printed message.
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define global_varaible static
#define array_len(array) (sizeof(array)/sizeof(array[0]))

enum Cards
{
	None         = 0,
	Ace   	     = 1, 
	FaceCard     = 10,
	AceSecondary = 11,
};

global_varaible const int PlayerIndex = 1;
global_varaible const int MaxValue = 21;

global_varaible bool IsPlaying = true;
global_varaible int Hand[3] =
{
	0,
	0,
	0,
};

void
RunGame();

int
GenerateCardValue();

bool
IsHandABust(int);

bool
IsWinningHand(int);

int
main()
{
	srand(time(NULL));
	char c;
	int cardValue = 0;
	
	while (IsPlaying)
	{
		RunGame();
		printf("Continue playing? (y)\n");
		scanf("\n%c", &c);
		if (tolower(c) != 'y')
		{
			IsPlaying = false;
		}
	}

	return 0;
}

void
RunGame()
{
	bool DrawAce = false;
	int sum = 0;
	for (int i = 0; i < array_len(Hand); ++i)
	{
		Hand[i] = 0;
		int cardValue = GenerateCardValue();
		if (cardValue == Ace)
		{
			DrawAce = true;
			Hand[i] += AceSecondary;
		}
		else 
		{
			Hand[i] += GenerateCardValue();
		}
		sum += Hand[i];
	}

	if (IsHandABust(sum))
	{
		if (DrawAce)
		{
			printf("swapping ace values to avoid busting!\n");
			sum -= AceSecondary;
			sum += Ace;
		}
		else
		{
			printf("Sorry - you busted!\n");
		}
	}
	else if (IsWinningHand(sum))
	{
		printf("Congrats you won!\n");
	}

	printf("Hand Value: %d\n", sum);
}

int
GenerateCardValue()
{
	int cardValue = 0;
	cardValue = (Ace + (rand() % FaceCard));
	return (cardValue);
}

bool
IsHandABust(int handValue)
{
	bool isBust = (handValue > MaxValue) ? true : false;
	return (isBust);
}

bool
IsWinningHand(int handValue)
{
	bool isWinner = (handValue == MaxValue) ? true : false;
	return (isWinner);
}

