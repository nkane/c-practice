/*
 * Modify Program 7.10 to accept a character parameter named sortOrder. If
 * sortOrder is an a, swap() should exchange values only if the first value
 * in ascending order (smallest number first, largest number second). For
 * any other value, the function should return the values in descending
 * order (largest number first, smallest number second).
 *
 */

#include <stdio.h>

void
swap(char c, float *n1, float *n2);

int
main()
{
	float n1, n2;
	char c;
	printf("Enter in two numbers: ");
	scanf("%f %f", &n1, &n2);

	printf("Enter swap order (a/d): ");
	scanf("\n%c", &c);

	printf("Before:\n");
	printf("n1: %f\nn2: %f\n", n1, n2);

	swap(c, &n1, &n2);

	printf("After:\n");
	printf("n1: %f\nn2: %f\n", n1, n2);

	return 0;
}

void
swap(char c, float *n1, float *n2)
{
	float temp;
	switch (c)
	{
		case 'a':
		{
			// n1 = 15
			// n2 = 10
			// --> n1 = 10
			// --> n2 = 15
			if (*n1 > *n2)
			{
				temp = *n2;
				*n2 = *n1;
				*n1 = temp;
			}
		} break;

		default: 
		{
			// n1 = 10
			// n2 = 15
			// --> n1 = 15
			// --> n2 = 10
			if (*n2 > *n1)
			{
				temp = *n1;
				*n1 = *n2;
				*n2 = temp;
			}
		} break;
	}
}

