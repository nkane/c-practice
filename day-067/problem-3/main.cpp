/*
 * Write a function named seconds() that accepts the time in hours, minutes, 
 * and seconds; and determine the total number of seconds in the passed data. 
 * Write this function so that the total number of seconds is returned by the
 * function as an integer number.
 *
 * Create a second function that passes by reference of the variable that it
 * will operate directly on as well as the other values instead of a return value.
 *
 */

#include <stdio.h>

inline
int SecondsByValue(int, int, int);

inline
void SecondsByReference(int *, int, int, int);

int
main()
{
	int hours = 0, minutes = 0, seconds = 0;
	int time_value = 0, time_ptr = 0;

	printf("Enter in the hours: ");
	scanf("%d", &hours);

	printf("Enter in the minutes: ");
	scanf("%d", &minutes);
	
	printf("Enter in the seconds: ");
	scanf("%d", &seconds);

	time_value = SecondsByValue(hours, minutes, seconds);
	SecondsByReference(&time_ptr, hours, minutes, seconds);

	printf("time_value: %d\n", time_value);
	printf("time_ptr: %d\n", time_ptr);

	return 0;
}

inline
int SecondsByValue(int hours, int minutes, int seconds)
{
	return (((hours * 60) * 60) + (minutes * 60) + seconds);
}

inline
void SecondsByReference(int *value_ptr, int hours, int minutes, int seconds)
{
	(*value_ptr) = SecondsByValue(hours, minutes, seconds);
}

