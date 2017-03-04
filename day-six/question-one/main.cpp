/*
 * Write and execute a C program that calculates and displays the sum
 * of the numbers from 1 to 100. The formula for calculating this sum 
 * is sum = (n / 2) (2 * a + (n - 1) d), where n = number of terms to
 * to be added, a = the first number, and d = the difference between
 * each number.
 *
 * After confirming that the program is functioning correctly,
 * determine the sum of the integers from 100 to 1000
 */

#include <stdio.h>

inline int SumBetween(int, int, int);

int main(void)
{
	int a = 1, n = 100;
	printf("Sum of %d to %d : %d\n", a, n, SumBetween(n, a, 1));
	
	a = 100;
	n = 1000;
	printf("Sum of %d to %d : %d\n", a, n, SumBetween(n, a, 1));

	return 0;
}

inline int SumBetween(int n, int a, int diff)
{
	// (100 / 2) * ( 2 * 1 + (100 - 1) * 1)
	// 50 * ( 2 * 1 + (100 - 1) * 1)
	// 50 * ( 2 + 99 * 1)
	// 50 * ( 101 * 1)
	// 50 * 101
	// 5050

	// (1000 / 2) (2 * 100 + (1000 - 1) * 1)
	// 500 * ( 2 * 100 + (1000 - 1) * 1)
	// 500 * ( 200 + 999 * 1)
	// 500 * ( 1199 * 1)
	// 500 * 1199

	int result = ((n / 2) * ((2 * a + (n - 1)) * diff));

	return result;
}
