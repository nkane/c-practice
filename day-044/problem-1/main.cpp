/*
 *  A bowling team consists of five players. Each player bowls three games. Write a C
 *  program that uses a nested loop to enter each player's individual scores and then computes
 *  and displays the average score for each bowler. Assume that each bowler has the following scores:
 *
 * 1st bowler: 286 252 265
 * 2nd bowler: 212 186 215
 * 3rd bowler: 252 232 216
 * 4th bowler: 192 201 235
 * 5th bowler: 186 236 272
 *  
 */

#include <stdio.h>

#define global_variable static

#define row_len(array) (sizeof(array) / sizeof(array[0]))
#define column_len(array) (sizeof(array[0]) / sizeof(array[0][0]))

global_variable const float Bowler_Scores[5][3]
{
	// first bowler
	{
		286.0f, 252.0f, 265.0f,
	},
	// second bowler
	{
		212.0f, 186.0f, 215.0f,
	},
	// third bowler
	{
		252.0f, 232.0f, 216.0f,
	},
	// fourth bowler
	{
		192.0f, 201.0f, 235.0f,
	},
	// fifth bowler
	{
		186.0f, 236.0f, 272.0f,
	},
};

global_variable float Average_Scores[5]
{
	0.0f,
	0.0f,
	0.0f,
	0.0f,
	0.0f,
};

inline float
ComputeAverage(float, float);

int
main()
{
	int rows = row_len(Bowler_Scores);
	int columns = column_len(Bowler_Scores);
	float sum = 0.0f;

	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < columns; ++c)
		{
			sum += *(*(Bowler_Scores + r) + c);
		}

		printf("Average for Bowler %d: %.2f\n", (r + 1), ComputeAverage(sum, columns));
		sum = 0.0f;
	}

	return 0;
}

inline float
ComputeAverage(float sum, float numberTotal)
{
	float result = 0.0f;
	result = (sum / numberTotal);
	return result;
}

