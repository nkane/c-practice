/*
 * Repeat previous exercise, but have your program declare the 
 * variable used to store the number as a single-percision variable.
 * Run the program four times. The first time, enter an integer, the
 * second time, enter a decimal number with fewer than six decimal places;
 * the third time, etner a number with more than six decimal places; and the
 * fourth time, enter a character. Using the output display, keep track of
 * what number your program actually accepted from the data you typed in.
 * What happened, if anything, and why?
 */

#include <stdio.h>

int
main(void)
{
	int y = 0;
	float x = 0.0f;

	printf("Enter in a value:\n");
	scanf("%f", &x);

	printf("Value Entered: %f\n", x);
	scanf("%d", &y);

	return 0;
}
