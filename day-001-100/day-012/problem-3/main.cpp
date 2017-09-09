/*
 * The formula for calculating the area of a triangle with Sides
 * a, b, and c can be calculated using Heron's formula: 
 * area = sqrt(s * (s - a) * (s - b) * (s - c)), where
 * s = (a + b + c) / 2. Using this formula, write, compile, and
 * execute a C program that calculates and displays the area
 * of a triangle having Sides of 3, 4, and 5 inches.
 */

#include <stdio.h>
#include <math.h>

struct Triangle
{
	float Sides[3];
};

inline Triangle
CreateTriangle(float, float, float);

inline float
ComputeAreaForTriangleF(Triangle *);

inline void
PrettyPrint(Triangle *, float);

int
main(void)
{
	Triangle T = CreateTriangle(3.0f, 4.0f, 5.0f);
	PrettyPrint(&T, ComputeAreaForTriangleF(&T));

	return 0;
}

inline float
ComputeAreaForTriangleF(Triangle * t)
{
	float result = ((t->Sides[0] + t->Sides[1] + t->Sides[2]));
	result = result / 2.0f;
	//s * (s - a) * (s - b) * (s - c)
	result = (result * (result - t->Sides[0]) * (result - t->Sides[1]) * (result - t->Sides[2]));
	result = sqrt(result);

	return result;
}

inline Triangle
CreateTriangle(float a, float b, float c)
{
	Triangle t = {};
	t.Sides[0] = a;
	t.Sides[1] = b;
	t.Sides[2] = c;

	return t;
}

inline void
PrettyPrint(Triangle *t, float r)
{
	printf("Triangle side one: %.2f\n", t->Sides[0]);
	printf("triangle side two: %.2f\n", t->Sides[1]);
	printf("triangle side three: %.2f\n", t->Sides[2]);
	printf("triangle side area: %.2f\n", r);
}
