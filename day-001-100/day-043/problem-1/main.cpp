/*
 * Four experiments are performed, each consisting of six test results. The result for each
 * experiment are given below. Write a C program using a nested loop to compute and display
 * the average of the test results for each experiment.
 *
 * 1st experiment results: 23.2, 31.5, 16.9, 27.5, 25.4, and 28.6
 * 2nd experiment results: 34.8, 45.2, 27.9, 36.8, 33.4, and 39.4
 * 3rd experiment results: 19.4, 16.8, 10.2, 20.8, 18.9, and 13.4
 * 4th experiment results: 36.9, 39.5, 49.2, 45.1, 42.7, and 50.6
 *
 */

#include <stdio.h>

#define global_variable static

// sizeof(array)       -> total size in bytes of array
// sizeof(array[0])    -> total size of a row in 2D array
// sizeof(array[0][0]) -> total size of a "cell" or element
#define row_len(array) (sizeof(array) / sizeof(array[0]))
#define column_len(array) (sizeof(array[0]) / sizeof(array[0][0]))

global_variable float Experiments[4][6]
{
	// One
	{
		23.2f, 
		31.5f, 
		16.9f,
		27.5f, 
		25.4f,
		28.6f,
	},
	// Two
	{
		34.8f, 
		45.2f, 
		27.9f,
		36.8f, 
		33.4f,
		39.4f,
	},
	// Three
	{
		19.4f, 
		16.8f, 
		10.2f,
		20.8f,
		18.9f,
		13.4f,
	},
	// Four
	{
		36.9f,
		39.5f,
		49.2f,
		45.1f,
		42.7f, 
		50.6f,
	},
};

inline float
ComputeAverage(float, float);

int main()
{
	int rows = row_len(Experiments);
	int columns = column_len(Experiments);
	float currentAverage = 0.0f;

	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < columns; ++c)
		{
			// NOTE(nick): stack overlfow
			// https://stackoverflow.com/questions/11177410/2d-array-and-pointer-in-c-how-to-access-elements
			// Current Row = *(Experiment + r)
			// Current Column = *(*(Experiments + r) + c)
			currentAverage += *(*(Experiments + r) + c);
		}

		printf("Average is: %.2f\n", ComputeAverage(currentAverage, columns));
		currentAverage= 0.0f;
	}
	
	return 0;
}


inline float
ComputeAverage(float total, float div)
{
	float result = 0.0f;
	result = (total / div);
	return result;
}

