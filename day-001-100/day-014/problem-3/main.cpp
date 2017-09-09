/*
 * Write a C program that displays the following prompt:
 * "Enter the radius of a circle:"
 *
 * After accepting a value for the radius, your program should
 * calculate and display the circumference of a circle.
 * (hint: circumference = 2 * 3.1416 * radius)
 */

#include <stdio.h>

#define PI_CONST 3.1416f

inline float
RequestValue();

struct Circle
{
	float Radius;
	float Circumference;
};


inline Circle
MakeCircle(float, float);

inline void
ComputeCircleCircumference(Circle *);

inline void
PrettyPrint(Circle *);

int
main(void)
{
	int nothing;
	Circle C = MakeCircle(RequestValue(), 0.0f);
	ComputeCircleCircumference(&C);
	PrettyPrint(&C);
	scanf("%d", &nothing);

	return 0;
}

inline float
RequestValue()
{
	float result = 0.0f;
	printf("Enter the radius of a circle:\n");
	scanf("%f", &result);
	return result;
}

inline Circle
MakeCircle(float r, float c)
{
	return Circle
	{
		r,
		c,
	};
}

inline void
ComputeCircleCircumference(Circle *c)
{
	c->Circumference = ((2.0f * PI_CONST) * c->Radius);
}

inline void
PrettyPrint(Circle *c)
{
	printf("Circle Radius: %.2f\n", c->Radius);
	printf("Circle Circumference: %.2f\n", c->Circumference);
}
