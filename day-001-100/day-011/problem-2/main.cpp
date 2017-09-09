/*
 * The work, W, in joules, required to stretch a spring a distance, d, 
 * in meters, is given by the equation, W = 1/2 k * d^2, where k is a
 * spring constant, in newtons per meter, that provides a measure of
 * the spring's stiffness. Using this equation, write A C program to
 * determine the work required in stretching a spring .55 meters, for
 * a spring having a spring constant of 300 newtons per meter.
 */

#include <stdio.h>

struct Spring
{
	float Stiffness;
	float Constant;
	float StretchDistance;
};

inline float ComputeSpringStiffness(Spring * );
inline void PrettyPrint(Spring *);

int
main(void)
{
	Spring S = 
	{
		0.0f,
		300.0f,
		0.55f,
	};

	S.Stiffness = ComputeSpringStiffness(&S);
	PrettyPrint(&S);

	return 0;
}

inline float
ComputeSpringStiffness(Spring * s)
{
	float result = ((0.5f * s->Constant) * (s->StretchDistance * s->StretchDistance));
	return result;
}

inline void
PrettyPrint(Spring *s)
{
	printf("Spring Constant: %.2f\n", s->Constant);
	printf("Spring Stretch Distance: %.2f\n", s->StretchDistance);
	printf("Spring Stiffness: %.2f\n", s->Stiffness);
}
