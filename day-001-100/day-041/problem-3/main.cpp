/*
 * Write a C program to produce the x and y coordinates for the following equations:
 *
 *  1) y = (3 * pow(x, 5)) - (2 * pow(x, 3) + x)
 *
 *  2) y = (1 + x + (pow(x, 2) / 2) + (pow(x, 3) / 6) + (pow(x, 4) / 24))
 *
 */

#include <stdio.h>
#include <math.h>

#define global_variable static

global_variable const int Loop = 6;

struct Vector2
{
	float X;
	float Y;
};

inline float
ComputeEqOneV2(Vector2 *);

inline float
ComputeEqTwoV2(Vector2 *);

int
main()
{
	Vector2 V2 = 
	{
		2.0f,
		0.0f,
	};
	
	while (V2.X <= Loop)
	{
		V2.Y = ComputeEqOneV2(&V2);
		printf("X: %.2f - Y: %.2f\n", V2.X, V2.Y);

		V2.Y = ComputeEqTwoV2(&V2);
		printf("X: %.2f - Y: %.2f\n\n", V2.X, V2.Y);

		++V2.X;
	}

	return 0;
}


inline float
ComputeEqOneV2(Vector2 *v)
{
	float result = 0.0f;

	result = (3.0f * pow(v->X, 5.0f) - (2 * pow(v->X, 3.0f) + v->X));

	return result;
}

inline float
ComputeEqTwoV2(Vector2 *v)
{
	float result = 0.0f;

	result = (1 + v->X + (pow(v->X, 2.0f) / 2.0f) + (pow(v->X, 3.0f) / 6.0f) + (pow(v->X, 4.0f) / 24.0f));

	return result;
}
