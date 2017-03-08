/*
 * Modify problem program number 4 to display the amount
 * of storage space you computer reserves for each data type.
 */

#include <stdio.h>

void printaddress(void*, int);

int main(void)
{
	char key, choice;
	int num, count;
	long date;
	float yield;
	double price;
	
	printaddress(&key, sizeof(key));
	printaddress(&choice, sizeof(choice));
	printaddress(&num, sizeof(num));
	printaddress(&count, sizeof(count));
	printaddress(&date, sizeof(date));
	printaddress(&yield, sizeof(yield));
	printaddress(&price, sizeof(price));

	return 0;
}

void printaddress(void *data, int size)
{
	printf("%p - size: %d\n", data, size);
}
