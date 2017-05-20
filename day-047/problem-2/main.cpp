/*
 * Write a function named check() that has three arguments. The first argument
 * should accept an integer number, the second argument a floating-point number,
 * and the third argument a double-percision number. The body of the function should just
 * display the vlaues of the data passed to the functions when it is called. (When tracing errors in
 * functions, it is very helpful to have the function display the values that have been passed into it.
 * Quite frequently, the error is not whawt the body of the function does with the data, but in the data
 * received and stored.)
 *
 */

#include <stdio.h>

inline void
check(int, float, double);

int
main()
{
	int x = 0;
	float y = 0.0f;
	double z = 0.0;

	printf("Enter in a int value:\n");
	scanf("%d", &x);

	printf("Enter in a float value:\n");
	scanf("%f", &y);

	printf("Enter in a double value:\n");
	scanf("%lf", &z);

	check(x, y, z);

	return 0;
}

inline void
check(int x, float y, double z)
{
	printf("Int: %d\n", x);
	printf("Float: %f\n", y);
	printf("Double: %lf\n", z);
}

