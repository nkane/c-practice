/*
 * The distance that light travels in one year is called a light year.
 * Given that light travles at a speed of 3 * 108 meters in one second,
 * determine the distance of a light year. The relevant formula is 
 * distance = speed * time.
 */

#include <stdio.h>

#define DAYS_IN_YEAR 365
#define HOURS_IN_DAY 24
#define MINS_IN_HOUR 60
#define SECS_IN_MIN 60

inline int CalculateSecondsInYear(int);

inline float CalculateDistanceTravelAtSpeedOfLight(int);

int main(void)
{
	int yearInSeconds = CalculateSecondsInYear(DAYS_IN_YEAR);

	float distanceTravelled = CalculateDistanceTravelAtSpeedOfLight(yearInSeconds);

	printf("Traveling at the speed of light for one year get you a distance of: %f\n", distanceTravelled);
	
	return 0;
}

inline int CalculateSecondsInYear(int days)
{
	int result = 0;
	result = (days * HOURS_IN_DAY);
	result *= MINS_IN_HOUR;
	result *= SECS_IN_MIN;
	return result;
}

inline float CalculateDistanceTravelAtSpeedOfLight(int seconds)
{
	float result = 0.0f;
	result = ((3.0f * 108.0f) * (float)seconds);
	return result;
}
