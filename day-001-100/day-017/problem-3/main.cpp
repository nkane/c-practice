/*
 * Repeat previous exercise, but have your program declare the variable
 * used to store the number as a double-precision variable. Run the program
 * four times. The first time, enter an integer, the second time, enter a
 * decimal with fewer than six decimal places; the third time, enter a number
 * with more than six decimal places; and the fourth time, enter a character.
 * Using the output displayed, keep track of what numbers your program actually
 * accept from the data you typed in. What happened, if anything, and why?
 */

#include <stdio.h>

int
main(void)
{
	int y;
	double x = 0.0l;

	printf("Enter in a value:\n");
	scanf("%lf", &x);

	printf("Value Entered: %lf\n", x);
	scanf("%d", &y);

	return 0;
}
