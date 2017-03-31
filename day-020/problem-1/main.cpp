/*
 * Given a program, use #define statements where for appropriate literals
 * Example Program: 
 * 
 * ...
 * float radius, circum;
 * printf("\nEnter a radius: ");
 * scanf("%f", &radius);
 * circum = 2.0 * 3.1416 * radius;
 * printf("\nThe circumference of the circle is %f", circum);
 * return 0;
 * ...
 */

#include <stdio.h>

#define PI 3.1416f
#define calculate_circumference(radius) ((2.0f * PI) * radius)

struct Circle
{
	float radius;
	float circumference;
};

inline Circle
CreateCircle();

inline void
CalculateCircumference(Circle *);

int
main(void)
{
	Circle C = CreateCircle();
	CalculateCircumference(&C);

	return 0;
}

inline Circle
CreateCircle()
{
	Circle c = 
	{
		0.0f,
		0.0f,
	};
	
	printf("Enter a radius:\n");
	scanf("%f", &c.radius);

	return c;
}

inline void
CalculateCircumference(Circle *c)
{
	c->circumference = calculate_circumference(c->radius);
	printf("Circle Circumference: %.2f\n", c->circumference);
}
