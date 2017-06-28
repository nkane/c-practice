/*
 * Write a program that includes the following declaration statements. Have the program
 * use the address operator and the printf() function to display the addresses corresponding
 * to each variable:
 *	
 *	char key, choice;
 *	int num, count;
 *	long date;
 *	float yield;
 *	double price;
 *
 * Display the amount of storage your computer reserves for each data type (use the sizeof
 * operator). With this information, determine if your computer sets aside storage for the
 * variables in the order they were declared.
 *
 */

#include <stdio.h>

int
main()
{
	char key, choice;
	int num, count;
	long date;
	float yield;
	double price;

	// char size - 1 byte (8 bits)
	printf("key: %c    - address: 0x%x - sizeof: %d\n", key, (int)&key, sizeof(key));
	printf("choice: %c - address: 0x%x - sizeof: %d\n\n", choice, (int)&choice, sizeof(choice));

	// int size - 4 bytes (32 bits)
	printf("num: %d   - address: 0x%x - sizeof: %d\n", num, (int)&num, sizeof(num));
	printf("count: %d - address: 0x%x - sizeof: %d\n\n", count, (int)&count, sizeof(count));

	// long size - 8 bytes (64 bits)
	printf("date: %ld - address: 0x%x - sizeof: %d\n\n", date, (int)&date, sizeof(date));
	
	// float size - 4 bytes (32 bits)
	printf("date: %f - address: 0x%x - sizeof: %d\n\n", yield, (int)&yield, sizeof(yield));
	
	// double size - 8 bytes (64 bits)
	printf("price: %e - address: 0x%x - sizeof: %d\n\n", price, (int)&price, sizeof(price));

	return 0;
}

