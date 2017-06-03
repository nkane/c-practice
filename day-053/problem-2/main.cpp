/*
 * Write a function that calculates the area, a, of a circle when its circumference, c, is given.
 * This function should call a second function which returns the radius, r, of the circle given c.
 * The relevant forumals are:
 * 	- r = c / 2 * pi
 * 	- a = pi * square(r)
 *
 */

#include <stdio.h>

#define square(value)(value * value)

#define global_varaible static

global_varaible const float Pi = 3.14159f;

inline float
AreaC(float, float);

inline float
RadiusC(float, float);

int
main()
{
	float circumference = 0.0f;

	printf("Enter a circle circumference:\n");
	scanf("%f", &circumference);

	printf("Area of circle is: %.2f\n", AreaC(circumference, Pi));

	return 0;
}

inline float
AreaC(float circumference, float pi)
{
	float radius = RadiusC(circumference, pi);
	return (pi * square(radius));
}

inline float
RadiusC(float circumference, float pi)
{
	return (circumference / (2.0f * pi));
}

