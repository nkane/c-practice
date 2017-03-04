/*
 * Write and execute a C program that calculates and displays the elapsed
 * time it took to make a 150-mile trip. The equation for computing elasped
 * time is elapsed time = distance / average speed. Assume the average speed
 * was 65 miles / hour.
 *
 * Then determine the elapsed time of a 204-mile trip, where the average
 * speed was 68 miles per hour.
 */

#include <stdio.h>

struct Trip
{
	int Distance;
	int AverageSpeed;
	float ElapsedTime;
};

inline void ComputeElapsedTime(Trip *);

inline void PrettyPrint(Trip *);

int main(void)
{
	Trip TripOne = { 150, 65, 0 };
	ComputeElapsedTime(&TripOne);
	PrettyPrint(&TripOne);

	Trip TripTwo = { 204, 68, 0 };
	ComputeElapsedTime(&TripTwo);
	PrettyPrint(&TripTwo);

	return 0;
}

inline void ComputeElapsedTime(Trip *trip)
{
	trip->ElapsedTime = ((float)trip->Distance / (float)trip->AverageSpeed);
}

inline void PrettyPrint(Trip *trip)
{
	printf("Trip Distance: %d\n", trip->Distance);
	printf("Trip Average Speed; %d\n", trip->AverageSpeed);
	printf("Trip Elapsed Time: %5.2f\n", trip->ElapsedTime);
}
