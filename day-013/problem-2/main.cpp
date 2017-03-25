/*
 * The time, T, in seconds, that a donut-sized space station must make
 * one rotation in gravity-free space to provide a human with the same
 * gravitational force as that experiened on Earth is given by the
 * equation T = 2pi * sqrt(r / g), where g is the gravitational force
 * on the Earth's surface, in meters / sec^2 and r is the outside
 * radius of the space station, in meters. Using this equation write,
 * compile, and run a C program that calculates and displays the rotation
 * time for a donut-sized space station that has an outer radius of 700
 * meters and g = 9.81 meters / sec^2
 */

#include <stdio.h>
#include <math.h>

#define GRAVITY_CONST 9.81f
#define PI_CONST 3.14f

struct SpaceStation
{
	 float Radius;
	 float RotationTime;
};

inline SpaceStation
CreateSpaceStation(float, float);

inline float
ComputeRotationTimeF(SpaceStation *);

inline void
PrettyPrint(SpaceStation *);

int
main(void)
{
	SpaceStation S = CreateSpaceStation(700.0f, 0.0f);
	S.RotationTime = ComputeRotationTimeF(&S);
	PrettyPrint(&S);

	return 0;
}


inline SpaceStation
CreateSpaceStation(float radius, float rotationTime)
{
	return SpaceStation {
		radius,
		rotationTime,
	};
}

inline float
ComputeRotationTimeF(SpaceStation *s)
{
	float result = ((2.0f * PI_CONST) * sqrt((s->Radius / GRAVITY_CONST)));
	return result;
}

inline void
PrettyPrint(SpaceStation *s)
{
	printf("Space Station Radius: %.2f\n", s->Radius);
	printf("Space Station Rotation: %.2f\n", s->RotationTime);
}
