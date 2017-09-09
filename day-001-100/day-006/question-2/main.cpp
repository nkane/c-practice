/*
 * Write a C program to calculate and display the value of the slope
 * of the line connecting the two points whose coordinates are (3, 7)
 * and (8, 12). Use the fact that the slope between two points having
 * coordinates (x1, y1) and (x2, y2) is (y2 - y1) / (x2 - x1).
 *
 * Next calculate the slope between (2, 10) and (12, 6), and
 * (2, 3) and (2, 4).
 */

#include <stdio.h>

struct Vector2
{
	float X;
	float Y;
};

inline float V2Slope(Vector2, Vector2); 
inline void PrettyPrint(Vector2, Vector2, float);

int main(void)
{
	Vector2 V1 = { 3, 7 };
	Vector2 V2 = { 8, 12 };

	float slope = V2Slope(V1, V2);
	PrettyPrint(V1, V2, slope);

	V1.X = 2;
	V1.Y = 10;

	V2.X = 12;
	V2.Y = 6; 

	slope = V2Slope(V1, V2); 
	PrettyPrint(V1, V2, slope);

	V1.X = 2;
	V1.Y = 3;

	V2.X = 2;
	V2.Y = 4;

	slope = V2Slope(V1, V2);
	PrettyPrint(V1, V2, slope);
		
	return 0;
}

inline float V2Slope(Vector2 pointOne, Vector2 pointTwo)
{
	float resultY = 0, resultX = 0;
	resultY = (pointTwo.Y - pointOne.Y);
	resultX = (pointTwo.X - pointOne.X);

	return (resultY > 0 && resultX > 0) ? resultY / resultX : 0;
}

inline void PrettyPrint(Vector2 pointOne, Vector2 pointTwo, float slope)
{
	printf("Point One: (%d, %d)\n", (int)pointOne.X, (int)pointOne.Y);
	printf("Point Two: (%d, %d)\n", (int)pointTwo.X, (int)pointTwo.Y);
	printf("Slope is: %f\n", slope);
}
