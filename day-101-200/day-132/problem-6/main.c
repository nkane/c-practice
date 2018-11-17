/*
 * Write a program that declares three single-dimensional arrays named miles, gallons,
 * and mpg. Each array should be capable of holding 10 elements. In the miles array,
 * store the numbers 240.5, 300.0, 189.6, 310.6, 280.7, 216.9, 199.4, 160.3, 177.4, 192.3.
 * In the gallons array, store the numbers 10.3, 15.6, 9.7, 14, 16.3, 15.7, 14.9, 10.7, 9.3,
 * 9.4. Each element of the mpg array should be calculated as the corresponding element to the
 * miles array divided by the equivalent element of the gallons array; for example,
 * mpg[0] = miles[0] / gallons[0]. Use pointers when calculating and displaying the elements of
 * the mpg array.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

#define SIZE 10

int
main()
{
	float miles[SIZE] = { 240.5f, 300.0f, 189.6f, 310.6f, 280.7f, 216.9f, 199.4f, 160.3f, 177.4f, 192.3f, };
	float gallons[SIZE] = { 10.3f, 15.6f, 9.7f, 14.0f, 16.3f, 15.7f, 14.9f, 10.7f, 9.3f, 9.4f, };
	float mpg[SIZE] = { 0.0f };
	float *milesPtr;
	float *gallonsPtr;
	float *mpgPtr;

	for (milesPtr = miles, gallonsPtr = gallons, mpgPtr = mpg;
	     mpgPtr < (mpg + len(mpg));
	     milesPtr++, gallonsPtr++, mpgPtr++)
	{
		*mpgPtr = (*milesPtr) / (*gallonsPtr);
		printf("Miles:   %6.2f\n", *milesPtr);
		printf("Gallons: %6.2f\n", *gallonsPtr);
		printf("MPG:     %6.2f\n\n", *mpgPtr);
	}

	return 0;
}
