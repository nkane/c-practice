/*
 * Write a C program to determine the distance an airplane travels on a runway
 * before takeoff. The equation for determing the distance, d, in meters
 * is d = 1/2 a * t^2, where a is the acceleration of the airplane in
 * meters per second squared, and t is the time, in seconds, that the
 * airplane remains on the runway before lifting off. Use an acceleration
 * of 3.5 meters / sec^2 and a time of 30 seconds.
 */

#include <stdio.h>

struct Airplane
{
	float LiftoffDistance;
	float Acceleration;
	float Time;
};

inline float SquareF(float);

inline float 
CalculateLiffoffDistanceF(Airplane *);

inline void
PrettyPrint(Airplane *);

int 
main(void) 
{
	Airplane A = 
	{
		0.0f,
		3.5f,
		30.0f,
	};

	A.LiftoffDistance = CalculateLiffoffDistanceF(&A);
	PrettyPrint(&A);

	return 0;
}

inline float SquareF(float f)
{
	return f * f;
}

inline float 
CalculateLiffoffDistanceF(Airplane * a)
{
	float result = ((0.5f * a->Acceleration) * (SquareF(a->Time)));
	return result;
}

inline void
PrettyPrint(Airplane * a)
{
	printf("Airplane Accerlation: %.2f meters per second squared\n", a->Acceleration);
	printf("Airplane Time: %.2f seconds - Squared: %.2f\n", a->Time, SquareF(a->Time));
	printf("Airplane liftoff distance: %.2f meters\n", a->LiftoffDistance);
}
