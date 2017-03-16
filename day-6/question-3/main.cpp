/*
 * Pendulums used in clocks, such as grandmother and grandfather clocks,
 * keep fairly accurate time for the following reason: When the length
 * of a pendulum is relatively large compared to the maximum arc of its
 * swing, the time to complete one swing is independent of both the
 * pendulum's weight and the maximum displacement of the swing. When
 * this condition is statisfied, the relationship between the time to
 * complete one swing and the length of the pendulum is given by the
 * the formula:
 * 
 * length = g * [time / (2 * pi)]^2
 *
 * where pi, accurate to four decimal places, is equal to 3.1416 and
 * g is the gravitation constant equal to 32.2 feet / second^2. When
 * the time of a complete swing is given in seconds, the length of
 * the pendulum is in feet. Using the given formula, write a C program
 * to calculate and display the length of a pendulum needed to produce
 * a swing that will be completed in one second. The length should be
 * displayed in inches and should have the folowing format:
 *
 * The length to complete one swing in one second is: _________
 */

#include <stdio.h>

#define PI 3.1416f

struct Clock 
{
	float Gravity;
	float Time;
};

inline float PendulumLength(Clock *);

int main(void)
{
	Clock C1 = { 32.0f, 1.0f };
	
	float length = PendulumLength(&C1);

	printf("The length to complete one swing in one second is: %f\n", length);

	return 0;
}

inline float PendulumLength(Clock *c)
{
	float result = 0.0f;
	result =  c->Gravity * (c->Time / (2.0f * PI));
	result *= result;
	return result;
}
