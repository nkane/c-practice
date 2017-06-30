/*
 * Rewrite the findMax() function in Program 6.2 so that the variable
 * max is declared in main() and the maximum value of the two passed
 * numbers is written directly to max. (Hint: The address of max will
 * also have to be passed to findMax().)
 *
 */

#include <stdio.h>

void 
findMax(float *max, float n1, float n2);

int
main()
{
	float max, n1, n2;

	printf("Enter in two values: ");
	scanf("%f %f", &n1, &n2);

	findMax(&max, n1, n2);

	printf("Max is: %f\n", max);

	return 0;
}

void 
findMax(float *max, float n1, float n2)
{
	*max = n1;
	if (n1 < n2) 
	{
		*max = n2;
	}
}
