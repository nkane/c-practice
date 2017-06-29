/*
 * Write a C function named time() that accepts an integer number of seconds 
 * and the addresses of three variables named hours, mins, and sec. The function
 * is to convert the passed numbers into an equivalent number of hours, minutes,
 * and seconds and directly alter the value of the respective variables using 
 * their passed addresses.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Seconds_In_Hour = 3600;
global_variable const int Seconds_In_Min  = 60;


void
Time(int value, int *hours, int *minutes, int *seconds);

int
main()
{
	int hours = 0, minutes = 0, seconds = 0, valueInSeconds = 0;

	printf("Enter in a value for seconds: ");
	scanf("%d", &valueInSeconds);

	Time(valueInSeconds, &hours, &minutes, &seconds);

	printf("Hours: %d\n", hours);
	printf("Minutes: %d\n", minutes);
	printf("Seconds: %d\n", seconds);

	return 0;
}


/*
 * 1 hour   = 60 minutes -> 60 minutes = 3600 seconds
 * 1 minute = 60 seconds
 *
 */
void
Time(int value, int *hours, int *minutes, int *seconds)
{
	while (value > 0)
	{
		if (value >= Seconds_In_Hour)
		{
			(*hours) += 1;
			value -= Seconds_In_Hour;
		}
		else if (value >= Seconds_In_Min)
		{
			(*minutes) += 1;
			value -= Seconds_In_Min;
		}
		else 
		{
			(*seconds) += 1;
			value--;
		}
	}
}

