/*
 * Write a C program that uses the declaration statement double num;.
 * Then use the function call scanf("%f", &num); to input a value into num.
 * (Notice that we have used the wrong control sequence for the variable num
 * Run your program and enter a deciaml number. Using a printf() function call,
 * have your program display the number stored in num. Determine what problem
 * you can run into when an incorrect control squence is used in scanf().
 */

#include <stdio.h>

int
main(void)
{
	int x;
	double num;

	printf("Enter a value:\n");

	// NOTE(nick): this is incorrect on purpose, per the problem above
	scanf("%lf", &num);

	printf("Value entered: %f\n", (float)num);
	scanf("%d", &x);

	return 0;
}
