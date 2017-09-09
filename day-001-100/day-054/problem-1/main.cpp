/*
 * Write a function named winPercent() that accepts the number of wins and losses
 * that a team achieves and returns its winning percentage. Use the formula:
 *
 * 	- winning percentage = 100 * wins / (wins + losses)
 *
 */

#include <stdio.h>

inline float
WinPercentage(float, float);

int
main()
{
	float wins = 0.0f, losses = 0.0f; 

	printf("Enter in the number of wins:\n");
	scanf("%f", &wins);

	printf("Enter in the number of losses:\n");
	scanf("%f", &losses);

	printf("Win Percentage: %.2f\n", WinPercentage(wins, losses));

	return 0;
}

inline float
WinPercentage(float w, float l)
{
	return (100.0f * w / (w + l));
}

