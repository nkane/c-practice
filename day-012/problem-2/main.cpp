/*
 * Write, compile, and execute a C program that calculates the distance
 * between two points whose coordinates are (7, 12) and (3, 9). use the 
 * fact that the distance between two points having coordinates (x1, y1)
 * and (x2, y2) is distance = sqrt((x1 - x2)^2 + (y1 - y2)^2).
 */

#include <stdio.h>
#include <math.h>

struct Vector2
{
	float X;
	float Y;
};

inline Vector2 
CreateVector(float, float);

inline float
ComputeDistanceBetweenVector2(Vector2 *, Vector2 *);

inline void
PrettyPrint(float);

int
main(void)
{
	Vector2 v1 = CreateVector(7, 12);
	Vector2 v2 = CreateVector(3, 9);
	PrettyPrint(ComputeDistanceBetweenVector2(&v1, &v2));

	return 0;
}

inline float
ComputeDistanceBetweenVector2(Vector2 *v1, Vector2 *v2)
{
	float result = sqrt(pow((v1->X - v2->X), 2) + pow((v1->Y - v2->Y), 2));
	return result;
}

inline Vector2 
CreateVector(float x, float y)
{
	return Vector2 {
		x, 
		y,
	};
}


inline void
PrettyPrint(float result)
{
	printf("Distance: %.2f\n", result);
}
