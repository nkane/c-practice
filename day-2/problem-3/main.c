/*
 * You purchase a laptop computer $889. The sales tax rate is
 * 6 percent. Write and execute a C program that calculates and
 * displays the total purchase price.
 */

#include <stdio.h>

#define PRICE 889.00f
#define TAX_RATE 0.06f

float CalculatePrice(float, float);

int main(void)
{
	float totalPurchasePrice = CalculatePrice(PRICE, TAX_RATE);
	
	printf("Sticker Price: %.2f\n", PRICE);
	printf("Tax Rate: %.2\n", TAX_RATE);
	printf("The Total Price is: $%.2f\n", totalPurchasePrice);

	return 0;
}

float CalculatePrice(float stickerPrice, float taxDecimalRate)
{
	// totalPrice = stickerPrice + (stickerPrice * taxDecimalRate);
	float result = (stickerPrice + (stickerPrice * taxDecimalRate));
	return result;
}
