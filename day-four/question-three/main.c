/*
 * In 1995, the Brooklyn Dodgers baseball team won 98 games and lost 55.
 * Using this information write, compile, and execute a C program that
 * calculates and displays the team's winning percentage for 1955.
 */

#include <stdio.h>

#define WINS 98
#define LOSSES 55

// winnng percentage -> totalgames / wongames?

inline float WinPercentage(int, int);

int main(void)
{
	printf("Wins: %d - Losses: %d\n", WINS, LOSSES);
	printf("Win Percentage: %5.2f\n", WinPercentage(WINS, LOSSES));

	return 0;
}

inline float WinPercentage(int wins, int losses)
{
	float result = (((float)wins / ((float)wins + (float)losses)) * 100.0f);
	return result;
}
