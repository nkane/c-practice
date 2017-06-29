/*
 * Replace the calc() function used in Program 7.8 with two functions named
 * computeSum() and computeProduct(). The computeSum() function should calculate
 * and directly return the sum of three values passed to it, while the
 * computeProduct() function should calculate and directly return the product
 * of three values passed to it.
 *
 */

#include <stdio.h>

// replacing with two function calls
/*
void
calc(float, float, float, float *, float *);
*/

float
ComputeSum(float, float, float);

float
ComputeProduct(float, float, float);

int
main()
{
	float firstNumber, secondNumber, thirdNumber, sum, product;

	printf("Enter in three numbers: " );
	scanf("%f %f %f", &firstNumber, &secondNumber, &thirdNumber);
	
	sum = ComputeSum(firstNumber, secondNumber, thirdNumber);
	product = ComputeProduct(firstNumber, secondNumber, thirdNumber);

	// replacing with two function calls
	//calc(firstNumber, secondNumber, thirdNumber, &sum, &product);

	printf("\nThe sum of the entered numbers is: %6.2f", sum);
	printf("\nThe product of the entered numbers is: %6.2f", product);

	return 0;
}

// replacing with two function calls
/*
void
calc(float n1, float n2, float n3, float *sumAddress, float *productAddress)
{
	*sumAddress = n1 + n2 + n3;
	*productAddress = n1 * n2 * n3;
}
*/

float
ComputeSum(float n1, float n2, float n3)
{
	return (n1 + n2 + n3);
}


float
ComputeProduct(float n1, float n2, float n3)
{
	return (n1 * n2 * n3);
}

