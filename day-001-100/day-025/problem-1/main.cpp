/*
 * The area of any triangle with sides a, b, and c can be computed
 * using Heron's formula:
 * - area = sqrt(s * (s - a) * (s - b) * (s - c))
 * - Where s = (a + b + c) / 2
 *
 * Using these formulas, write a C program that accepts values for the sides
 * a, b, and c from the user. Then calculate and display the area for the case
 * where the value of s * (s - a) * (s - b) * (s - c) is positive. If the value
 * of this expression is negative, our program should display a message
 * indicating that the three sides entered do not represent the sides of a triangle.
 */

#include <stdio.h>
#include <math.h>

#define len(array) (sizeof(array) / sizeof(array[0]))

struct Triangle
{
	float Sides[3];
	float Area;
};

inline Triangle
CreateTriangle();

inline void
ComputeTriangleAreaF(Triangle *);

inline void
PrettyPrint(Triangle *);

int
main(void)
{
	Triangle T = CreateTriangle();
	PrettyPrint(&T);

	return 0;
}

inline Triangle
CreateTriangle()
{
	Triangle T = {};

	for (int i = 0; i < len(T.Sides); ++i)
	{
		printf("Enter in a value for sides %d:\n", i + 1);
		scanf("%f", &T.Sides[i]);
	}

	ComputeTriangleAreaF(&T);

	return T;
}

inline void
ComputeTriangleAreaF(Triangle *T)
{
	float s = 0.0f;
	for (int i = 0; i < len(T->Sides); ++i)
	{
		s += T->Sides[i];
	}
	
	s /= 2;

	if (s > 0) 
	{
		T->Area = (s - T->Sides[0]) * (s - T->Sides[1]) * (s - T->Sides[2]);
		T->Area *= s;
		T->Area = sqrt(T->Area);
	}
	else
	{
		T->Area = 0.0f;
		printf("ERROR: values provided are not correct for a triangle\n");
	}
}

inline void
PrettyPrint(Triangle *T)
{
	for (int i = 0; i < len(T->Sides); ++i)
	{
		printf("Triangle Side %d: %.2f\n", i + 1, T->Sides[i]);
	}

	if (T->Area > 0.0f)
	{
		printf("Triangle Area: %.2f\n", T->Area);
	}
}
