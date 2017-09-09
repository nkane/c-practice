/*
 * In the game of blackjack, the cards 2 through 10 are counted at their face value,
 * regardless of suit, all face cards (jack, queen, and king) are counted as 10, and an
 * ace is counted as either a 1 or an 11, depending on the total count of all the cards
 * in a player's hand. The ace is counted as 11 only if the resulting total value of all
 * cards in a player's hand does not exceed 21, else it is counted as a 1. Using this 
 * information, write a C program that accepts three card values as inputs (a 1 corresponding
 * to an ace, a 2 corresponding to a two, and so on), calculate the total value of the hand
 * appropriately, and displays the value of the three cards with a printed message.
 */

#include <stdio.h>

#define len(array) (sizeof(array) / sizeof(array[0]))

struct CardHand
{
	int Cards[3];
	int HandValue;
};

inline CardHand
CreateCardHand();

inline int
ComputeHandValue(CardHand *);

int
main()
{
	CardHand C = CreateCardHand();

	return 0;
}

inline CardHand
CreateCardHand()
{
	CardHand C = {};
	
	for (int i = 0; i < len(C.Cards); ++i)
	{
		printf("What is the number value of the %d cards:\n", i + 1);
		scanf("%d", &C.Cards[i]);
	}

	C.HandValue = ComputeHandValue(&C);

	return C;
}

inline int
ComputeHandValue(CardHand *c)
{
	int sumOne = 0;
	int sumTwo = 0;

	for (int i = 0; i < len(c->Cards); ++i)
	{
		if (c->Cards[i] == 1) 
		{
			// Use as 11
			sumOne += 11;

			// Use as 1
			sumTwo += 1;
		}
		else if (c->Cards[i] <= 10)
		{
			sumOne += c->Cards[i];
			sumTwo += c->Cards[i];
		}
	}

	if (!(sumOne == sumTwo))
	{
		if (sumOne > 21)
		{
			// this is a bust!
			return sumTwo;
		} else if (sumTwo > 21)
		{
			return sumOne;
		}
	}

	return sumOne;
}
