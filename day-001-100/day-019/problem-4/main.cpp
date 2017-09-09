/*
 * The computed value between 1.674 = 1.322 should be 2.99, not 3.00
 * figure out a way to compute the correct value using a (int) cast
 */

#include <stdio.h>
#include <math.h>

int
main(void)
{
	double a, b, c;
	a = 1.674;
	b = 1.322;

	printf("\n%4.2f", a);
	printf("\n%4.2f", b);
	printf("\n--------");

	int x = (a * 100);
	int y = (b * 100);

	c = ((x + y) * 0.01);
	
	// should print 2.99
	// but prints 3.00
	printf("\n%.2f\n", c);

	return 0;
}
