/*
 * When a particular rubber ball is dropped from a given height (in meters), its
 * impact speed (in meters/second) when it hits the ground is given by the formula
 * speed = sqrt(2 * g * height). The ball then rebounds to 2/3 the height from which it
 * last fell. Using this information write, test, and run a C program that calculates 
 * and displays the impact speed of the first three bounces and the rebound height of
 * each bounce. Test your program using an initial height of 2.0 meters. Run the program
 * twice and compare the results for dropping the ball on Earth (g = 9.81 meters per sec^2)
 * and on the moon (g = 1.67 meters per sec^2)
 */

#include <stdio.h>
#include <math.h>

#define EARTH_GRAV 9.81f
#define MOON_GRAV 1.67f

#define len(array) (sizeof(array) / sizeof(array[0]))
#define compute_speed(gravity, height) (sqrt((2.0f * gravity * height)))
#define compute_rebound(height) (height * (2.0f / 3.0f))

struct Ball 
{
	float HeightHeld;
	float FallSpeed;
	float Rebounds[3];
};

inline Ball
CreateBall(float heightHeld);

inline void
ComputeBallSpeedAndRebound(Ball *, float);

inline void
PrettyPrint(Ball *, Ball *);

int
main(void)
{
	Ball B1 = CreateBall(2.0f);
	Ball B2 = CreateBall(2.0f);

	ComputeBallSpeedAndRebound(&B1, EARTH_GRAV);
	ComputeBallSpeedAndRebound(&B2, MOON_GRAV);

	PrettyPrint(&B1, &B2);

	return 0;
}

inline Ball
CreateBall(float heightHeld)
{
	Ball B = 
	{
		heightHeld,
		0.0f,
	};

	return B;
}

inline void
ComputeBallSpeedAndRebound(Ball *b, float gravity)
{
	b->FallSpeed = compute_speed(gravity, b->HeightHeld);

	for (int i = 0; i < len(b->Rebounds); ++i)
	{
		if (i == 0)
		{
			b->Rebounds[i] = compute_rebound(b->HeightHeld);
		} else
		{
			b->Rebounds[i] = compute_rebound(b->Rebounds[i - 1]);
		}
	}
}

inline void
PrettyPrint(Ball *b1, Ball *b2)
{
	int x = 0;
	printf("Ball 1 Height Held: %.2f\n", b1->HeightHeld);
	printf("Ball 1 Fall Speed: %.2f\n", b1->FallSpeed);

	for (int i = 0; i < len(b1->Rebounds); ++i)
	{
		printf("Ball 1 bounce %d: %.2f\n", i + 1, b1->Rebounds[i]);
	}

	printf("\nBall 2 Height Held: %.2f\n", b2->HeightHeld);
	printf("Ball 2 Fall Speed: %.2f\n", b2->FallSpeed);
	for (int i = 0; i < len(b2->Rebounds); ++i)
	{
		printf("Ball 2 bounce %d: %.2f\n", i + 1, b2->Rebounds[i]);
	}
	printf("Enter in any number to end ...\n");
	scanf("%d", &x);
}

