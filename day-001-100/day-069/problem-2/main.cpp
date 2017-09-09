/*
 * Enter program and execute program 7.10
 *
 */

#include <stdio.h>

void
swap(int *n1Address, int *n2Address);

void
swapXor(int *n1Address, int *n2Address);

int
main()
{
	int n1, n2;

	printf("Enter two numbers: ");
	scanf("%d %d", &n1, &n2);

	printf("\nBefore the call to swap()\n");
	printf("  The value in n1 is: %d\n", n1);
	printf("  The value in n2 is: %d\n", n2);

	swap(&n1, &n2);

	printf("\nAfter the call to swap()\n");
	printf("  The value in n1 is: %d\n", n1);
	printf("  The value in n2 is: %d\n", n2);

	printf("\nBefore the call to swapXor()\n");
	printf("  The value in n1 is: %d\n", n1);
	printf("  The value in n2 is: %d\n", n2);

	swapXor(&n1, &n2);

	printf("\nAfter the call to swapXor()\n");
	printf("  The value in n1 is: %d\n", n1);
	printf("  The value in n2 is: %d\n", n2);

	return (0);
}

void
swap(int *n1Address, int *n2Address)
{
	int temp = *n1Address;
	*n1Address = *n2Address;
	*n2Address = temp;
}

void
swapXor(int *n1Address, int *n2Address)
{
	/*
	 * xor swap example:
	 * x = 4 [0100]
	 * y = 2 [0010]
	 *
	 * x ^= y
	 *  0100
	 * ^0010
	 * ------
	 *  0110 -> x = 6
	 *  
	 *  y ^= x
	 *  0010
	 * ^0110
	 * -----
	 *  0100 -> y = 4
	 *  
	 * x ^= y
	 *  0110
	 * ^0100
	 * -----
	 *  0010 -> x = 2
	 *
	 */
	if (n1Address != n2Address) 
	{
		*n1Address ^= *n2Address;
		*n2Address ^= *n1Address;
		*n1Address ^= *n2Address;
	}
}

