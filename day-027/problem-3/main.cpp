/*
 * Rewrite Program 4.6 using a character variable for the select code:
 *
 * #include <stdio.h>
 * 
 * int main()
 * {
 *	int opselect;
 *	float fnum, snum;
 * 	
 *	printf("Please type in two numbers: ");
 *	scanf("%f %f", &fnum, &snum);
 *	printf("Enter a select code:");
 *	printf("\n 1 for addition");
 *	printf("\n 2 for multiplication");
 *	printf("\n 3 for division : ");
 *	scanf("%d", &opselect);
 *	
 *	switch (opselect)
 *	{
 *		case 1: 
 *			printf("The sum of the numbers entered is %6.3f\n", fnum + snum);
 *			break;
 		case 2:
			printf("The product of the numbers entered is %6.3f\n", fnum * snum);
			break;
		case 3:
			if (snum != 0.0) 
				printf("The first number divided by the second is %6.3f\n", fnum / snum);
			else
				printf("Division by zero is not allowed!\n");
			break;
 *	}
 *	
 *	return 0;
 * }
 */

#include <stdio.h>

int
main()
{
	return 0;
}
