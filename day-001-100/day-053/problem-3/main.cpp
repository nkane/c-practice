/*
 * The volume of a right cicular cylinder is given by its radius squared times its height
 * times pi. Write a funciton that accepts two single-precision argumenst corresponding to
 * the cylinder's radius and height, respectively, and returns the cylinder's volume.
 *
 */

#include <stdio.h>

#define square(value)(value * value)

#define global_variable static

global_variable const float Pi = 3.14159f;

inline float
VolumeCylinder(float, float, float);

int
main()
{
	float radius = 0.0f, height = 0.0f;

	printf("Enter in circular cylinder radius:\n");
	scanf("%f", &radius);

	printf("Enter in circular cylinder height:\n");
	scanf("%f", &height);

	printf("Cylinder volume: %.2f\n", VolumeCylinder(radius, height, Pi));

	return 0;
}

inline float
VolumeCylinder(float radius, float height, float pi)
{
	float result = 0.0f;
	result = (square(radius) * height * pi);
	return result;
}

