/*
 * An automobile travels at an average speed of 53 miles per hour for four hours.
 * Write a C program that displays the distance, in miles, by the car every half-hour
 * until end of the trip.
 */

#include <stdio.h>

#define global_variable static

global_variable const float Average_Speed_Rate = 53.0f;
global_variable const float Total_Trip_Time = 4.0f;

struct Travel
{
	float AverageSpeed;
	float CurrentDistance;
	float TotalTime;
	float CurrentTime;
};

inline Travel
CreateTravel(float averageSpeed, float totalTime);

inline float
ComputeCurrentDistance(Travel *);

inline void
PrettyPrint(Travel *);

int
main()
{
	Travel T = CreateTravel(Average_Speed_Rate, Total_Trip_Time);


	while (T.CurrentTime < T.TotalTime)
	{
		T.CurrentDistance = ComputeCurrentDistance(&T);
		PrettyPrint(&T);
		T.CurrentTime += 0.50f;
	}

	return 0;
}

inline Travel
CreateTravel(float averageSpeed, float totalTime)
{
	Travel T = 
	{
		averageSpeed,
		0.0f,
		totalTime,
		0.0f,
	};

	return T;
}

inline float
ComputeCurrentDistance(Travel *t)
{
	float result = 0.0f;
	result = (t->AverageSpeed * t->CurrentTime);
	return result;
}

inline void
PrettyPrint(Travel *t)
{
	printf("Current Time: %.2f hours - Current Distance: %.2f miles\n", t->CurrentTime, t->CurrentDistance);
}
