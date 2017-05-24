/*
 * Write a function named distance() that accepts the rectangular coordinates of two
 * points x1, y1 and x2, y2 and calculates and returns the distance between the two points
 * The distance, d, between two points is given by the formula:
 *
 * d = sqrt(squared(x2 - x1) + squared(y2 - y1))
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define global_variable static
#define internal static

#define square(value) (value * value)

struct Vector2
{
	float X;
	float Y;
};

inline Vector2 *
CreateVector2(float x, float y);

inline void 
DestoryVector2(Vector2 *);

internal float
DistanceBetweenV2(Vector2 *, Vector2 *);

int
main()
{
	float x = 0.0f, y = 0.0f;

	printf("Enter in x value:\n");
	scanf("%f", &x);
	printf("Enter in y value:\n");
	scanf("%f", &y);
	Vector2 * Position_1 = CreateVector2(x, y);

	printf("Enter in x value:\n");
	scanf("%f", &x);
	printf("Enter in y value:\n");
	scanf("%f", &y);
	Vector2 * Position_2 = CreateVector2(x, y);

	printf("Distance between points: %.2f\n", DistanceBetweenV2(Position_1, Position_2));

	DestoryVector2(Position_1);
	DestoryVector2(Position_2);

	return 0;
}

inline Vector2 *
CreateVector2(float x, float y)
{
	Vector2 *V = (Vector2 *)malloc(sizeof(Vector2));
	V->X = x;
	V->Y = y;
	return V;
}

inline void 
DestoryVector2(Vector2 * v2)
{
	if (v2)
	{
		free(v2);
	}
}

internal float
DistanceBetweenV2(Vector2 * v1, Vector2 * v2)
{
	float result = 0.0f;
	float x_values = (v2->X - v1->X);
	float y_values = (v2->Y - v1->Y);
	result = sqrt(square(x_values) + square(y_values));;
	return result;
}

