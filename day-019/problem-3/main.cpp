/*
 * Write a program to output the following:
 * "The sales tax is $1.80" -> (0.05 * 36)
 * "The total bill is $37.80" -> (37.80)
 */

#include <stdio.h>

int main(void)
{
	printf("The sales tax is $%.2f\n", (0.05f * 36));
	printf("The total bill is $%.2f\n",(37.80f));

	return 0;
}
