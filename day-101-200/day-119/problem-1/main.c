/*
 * Create a file with the following data containing the part number,
 * opening balance, number of items sold, and minimum stock required:
 *
 *
 * 	Part Number    Initial Amount    Quantity Sold    Minimum Amount
 * 	QA310          95                47               50
 * 	CM145          320               162              200
 * 	MS514          34                20               25
 * 	EN212          163               150              160
 *
 * Write a C program to create an inventory report based on the data in the
 * file created. The display should consist of the part number, current balance,
 * and amount that is necessary to bring the inventory to the minimum level.
 *
 */

#include <stdio.h>

typedef struct _record
{
	char PartNumber[6];
	int InitialAmount;
	int QuantitySold;
	int MinimumAmount;
} Record;

int
main()
{
	FILE *readFile = NULL;

	if (readFile = fopen("./data/test.dat", "r"))
	{
		Record r = { 0 };
		int currentBalance = 0;
		int restockAmount = 0;
		while (fscanf(readFile, "%[^,],%d,%d,%d ", r.PartNumber, &r.InitialAmount, &r.QuantitySold, &r.MinimumAmount) != EOF)
		{
			currentBalance = (r.InitialAmount - r.QuantitySold);
			restockAmount = (r.MinimumAmount - currentBalance);
			printf("Part Number: %s\n", r.PartNumber);
			printf("Initial Amount: %d\n", r.InitialAmount);
			printf("Quantity Sold: %d\n", r.QuantitySold);
			printf("Current Balance: %d\n", currentBalance);
			printf("Minimum Amount: %d\n", r.MinimumAmount);
			printf("Restock Amount: %d\n\n", restockAmount);
		}
		fclose(readFile);
	}

	return 0;
}
