/*
 * Write a funciton named hypotenuse() that accepts the length of two sides of a 
 * right trinagle as the parameters a, and b, respectively. The function should determine
 * and display the hypotenuse, c, of the triangle:
 *
 * - Use pythagoras' theorem 
 *   -> c^2 = a^2 + b^2
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define SquareF(value)(value * value)

struct Triangle
{
	float Side[3];
};

inline Triangle*
CreateTriangle(float, float);

inline float
ComputeHypotenuse(Triangle *);

inline void
DestroyTriangle(Triangle *);

int
main()
{
	float s1 = 0.0f, s2 = 0.0f;

	printf("Enter in side one: ");
	scanf("%f", &s1);
	
	printf("Enter in side two: ");
	scanf("%f", &s2);

	Triangle *T = CreateTriangle(s1, s2);

	T->Side[2] = ComputeHypotenuse(T);

	printf("The triangles hypothenuse is: %.2f\n", T->Side[2]);

	DestroyTriangle(t);

	return 0;
}

inline Triangle*
CreateTriangle(float sideOne, float sideTwo)
{
	Triangle *T = (Triangle *)malloc(sizeof(Triangle));
	T->Side[0] = sideOne;
	T->Side[1] = sideTwo;
	T->Side[2] = 0.0f;
	return T;
}

inline float
ComputeHypotenuse(Triangle *t)
{
	float result = 0.0f;
	result = ((SquareF(t->Side[0])) + (SquareF(t->Side[1])));
	return result;
}

inline void
DestroyTriangle(Triangle *t)
{
	if (t)
	{
		free(t);
	}
}

