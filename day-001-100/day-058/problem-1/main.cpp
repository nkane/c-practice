/*
 * Write two C functions, named dist() and angle(), respectively, to be used in converting
 * the rectanglar (x, y) coordinates of a point into polar form. That is, given an x and y position
 * on a Cartesian coordinate system, the dist() function must calculate and return the distance
 * from the origin, r, and the angle() function must calculate and return the angle from the 
 * x-axis, angle, specified by the point. The values of r and angle are referred
 * to as the point's polar coordinates. Use the relationship that:
 *
 * 	- r = sqrt(squaed(x) + squared(y))
 *	- angle = tan(-1) * (y / x), x != 0
 *
 */

#include <stdio.h>
#include <math.h>

struct Vec2
{
	float X;
	float Y;
};

inline float
Distance(Vec2 *);

inline float
Angle(Vec2 *);

int
main()
{
	Vec2 TestVec = 
	{
		12.0f,
		5.0f,
	};

	printf("Distance: %.2f\n", Distance(&TestVec));
	printf("Angle: %.2f\n", Angle(&TestVec));

	return 0;
}

inline float
Distance(Vec2 *Vec)
{
	float result = 0.0f;
	result = pow(Vec->X, 2) + pow(Vec->Y, 2);
	result = sqrt(result);
	return result;
}

inline float
Angle(Vec2 *Vec)
{
	float result = 0.0f;
	result = atan(Vec->Y / Vec->X) * 180.0f / 3.14159265f;
	return result;
}

