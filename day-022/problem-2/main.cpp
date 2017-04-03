/*
 * Write a C program that prompts the user for a cost per item,
 * number of items purchased, and a discount rate. That program should
 * then calculate and print the total cost, discounted total cost, tax due
 * and amount due. Use the formulas:
 * total cost = number of items * cost per item 
 * total cost (discounted) = total cost - (discount rate * total cost)
 * tax due = total cost * TAXRATE
 * amount due = total cost + tax due
 */

#include <stdio.h>

#define compute_tax_due(totalCost, taxRate) (totalCost * taxRate)
#define compute_bill(totalCost, taxRate) (totalCost + compute_tax_due(totalCost, taxRate))

struct Receipt
{
	float PreTaxCost;
	float PostTaxCost;
	float DiscountRate;
};

inline Receipt
CreateReceipt();

inline float
FinializeBill(Receipt *, float);

int
main(void)
{
	float taxRate = 0.0f;
	Receipt R = CreateReceipt();

	printf("Enter in the tax rate (e.g., 0.06 = 6%):\n");
	scanf("%f", &taxRate);

	printf("Total Bill: %.2f\n", FinializeBill(&R, taxRate));

	return 0;
}

inline Receipt
CreateReceipt()
{
	Receipt R = {};
	float costPerItem, numberItemsPurchased;
	printf("Enter in a cost per item:\n");
	scanf("%f", &costPerItem);

	printf("Enter in the amount of times purchased:\n");
	scanf("%f", &numberItemsPurchased);

	printf("Enter in the discount rate (e.g., 0.06 = 6%):\n");
	scanf("%f", &R.DiscountRate);

	R.PreTaxCost = (numberItemsPurchased * costPerItem);
	R.PostTaxCost = (R.PreTaxCost - (R.DiscountRate * R.PreTaxCost));

	return R;
}

inline float
FinializeBill(Receipt *r, float taxRate)
{
	float result = compute_bill(r->PostTaxCost, taxRate);
	return result;
}
