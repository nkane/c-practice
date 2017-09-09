/*
 * Write a C program to calculate and sipaly the coordinates of the midpoint
 * of the line segment connecting the points (3, 4) and (10, 12). Use the fact
 * that the coordinates of the midpoint between two points having coordinates
 * (x1, y1) and (x2, y2) are ((x1 + x2) / 2, (y1 + y2) / 2). You program should
 * produce the following display:
 * 
 * The x midpoint coordinate is ______
 * The y midpoint coordinate is ______
 * 
 * Additionally, caclulate the midpoint for (2, 10) and (12, 6)
 */

#include <stdio.h>

#define compute_mid_x(x1, x2) (x1 + x2 / 2.0f)
#define compute_mid_y(y1, y2) compute_mid_x(y1, y2)

struct Vector2 
{
	float X;
	float Y;
};

inline Vector2
CreateVector2();

inline Vector2
ComputeMidPoint(Vector2 *V1, Vector2 *V2);

inline void
PrettyPrint(Vector2 *V1, Vector2 *V2, Vector2 *MidPoint);

int
main(void)
{
	Vector2 V1 = CreateVector2();
	Vector2 V2 = CreateVector2();
	Vector2 MidPoint = ComputeMidPoint(&V1, &V2);
	PrettyPrint(&V1, &V2, &MidPoint);

	return 0;
}

inline Vector2
CreateVector2()
{
	Vector2 V = {};
	printf("Enter a X value:\n");
	scanf("%f", &V.X);

	printf("Enter a Y value:\n");
	scanf("%f", &V.Y);

	return V;
}

inline Vector2
ComputeMidPoint(Vector2 *V1, Vector2 *V2)
{
	Vector2 V = {};
	V.X = compute_mid_x(V1->X, V2->X);
	V.Y = compute_mid_y(V1->Y, V2->Y); 
	return V;
}

inline void
PrettyPrint(Vector2 *V1, Vector2 *V2, Vector2 *Midpoint)
{
	int x = 0;
	printf("Vector 1: (%.2f, %.2f)\n", V1->X, V1->Y);
	printf("Vector 2: (%.2f, %.2f)\n", V2->X, V2->Y);
	printf("Midpoint: (%.2f, %.2f)\n", Midpoint->X, Midpoint->Y);
	scanf("%d", &x);
}
