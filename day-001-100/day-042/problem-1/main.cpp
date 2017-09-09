/*
 * The x and y coordinates, as an equatin of time, t, of a projectile fired with an initial
 * velocity v at an angle of theta with respect to the ground is given by:
 *
 * x = v * t * cos(theta)
 * y = v * t * sin(theta)
 *
 * Using these formulas, write a C program that displays a table of x and y values for a
 * projectile fired with an initial velocity of 500 feet per second at an angle of 22.8 degrees.
 * (Hint: Remember to convert to radian measure.) The table should contain values corresponding
 * to the time interval 0 to 10 seconds in incremnts of one-half seconds.
 *
 * Radians:
 * - 2 * Pi * radians = 360 degrees
 * - pi * radians = 180 degrees
 *
 *  - 1 radian = 180 degrees / pi
 *  - pi / 180 * radians = 1 degree
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define global_variable static 

global_variable const float Half_Circle		= 180.0f;
global_variable const float Pi 			= 3.1416f;
global_variable const float Feet_Per_Second 	= 500.0f;
global_variable const float Theta_Const         = 22.8f;
global_variable const float Time_Final 		= 10.0f;

struct Vector2
{
	float X;
	float Y;
};

struct Projectile
{
	Vector2 *V2;
	float Velocity;
	float Theta;
	float Radians;
	float Time;
};

inline Vector2 *
CreateVector2(float, float);

inline void
DestoryVector2(Vector2 *);

inline Projectile *
CreateProjectile(Vector2 *, float, float, float);

inline void
DestoryProjectile(Projectile *);

inline float
ComputeThetaRadians(float, float);

inline float
ComputeV2XPosition(Projectile *);

inline float
ComputeV2YPosition(Projectile *);

inline void
PrettyPrint(Projectile *);

int
main()
{
	Vector2 *V2 = CreateVector2(0.0f, 0.0f);
	Projectile *P = CreateProjectile(V2, Feet_Per_Second, Theta_Const, 0.0f);

	while (P->Time <= Time_Final)
	{
		P->V2->X = ComputeV2XPosition(P);
		P->V2->Y = ComputeV2YPosition(P);
		PrettyPrint(P);
		P->Time += 0.5f;
	}

	DestoryProjectile(P);
	DestoryVector2(V2);
	return 0;
}


inline Vector2 *
CreateVector2(float x, float y)
{
	Vector2 *V2 = (Vector2 *)malloc(sizeof(Vector2));
	V2->X = x;
	V2->Y = y;
	return V2;
}

inline void
DestoryVector2(Vector2 *v2)
{
	if (v2)
	{
		free(v2);
	}
}

inline Projectile *
CreateProjectile(Vector2 *v2, float velocity, float theta, float time)
{
	Projectile *P = (Projectile *)malloc(sizeof(Projectile));
	P->V2 = v2;
	P->Velocity = velocity;
	P->Theta = theta;
	P->Radians = ComputeThetaRadians(theta, Pi);
	P->Time = time;
	return P;
}

inline void
DestoryProjectile(Projectile *p)
{
	if (p)
	{
		free(p);
	}
}

inline float
ComputeThetaRadians(float theta, float pi)
{
	float result = 0.0f;
	result = (theta * pi);
	result = (result / Half_Circle);
	return result;
}

inline float
ComputeV2XPosition(Projectile *p)
{
	float result = 0.0f;
	result = (p->Velocity * p->Time * cos(p->Radians));
	return result;
}

inline float
ComputeV2YPosition(Projectile *p)
{
	float result = 0.0f;
	result = (p->Velocity * p->Time * sin(p->Radians));
	return result;
}

inline void
PrettyPrint(Projectile *p)
{
	printf("Velocity: %.2f ft/sec\n", p->Velocity);
	printf("Theta: %.2f degrees\n", p->Theta);
	printf("Radians: %.2f\n", p->Radians);
	printf("Time: %.2f\n", p->Time);
	printf("{ x: %.2f , y: %.2f }\n\n\n", p->V2->X, p->V2->Y);
}

