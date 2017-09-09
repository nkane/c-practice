/*
 * Write a C program that prmpts the user to type a number. Have your program
 * accept the number as an integer and immediately display  the integer using
 * a printf() function call. Use variable inputs (i.e., floats, chars, and etc).
 */
#include <stdio.h>

int
main(void)
{
	int x = 0;

	printf("Enter in a value:\n");
	scanf("%d", &x);

	printf("Integer Value: %d\n", x);
	scanf("%d", &x);

	return 0;
}
