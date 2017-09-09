/*
 * Write a C program that includes the following declaration
 * statements:
 * char key, choice;
 * int num, count;
 * long date;
 * float yield;
 * double price;
 * 
 * Have the program use the address opereator and the printf()
 * function to display the addresses corresponding to each variable.
 */

#include <stdio.h>

void printaddress(void*);

int main(void)
{
	char key, choice;
	int num, count;
	long date;
	float yield;
	double price;
	
	printaddress(&key);
	printaddress(&choice);
	printaddress(&num);
	printaddress(&count);
	printaddress(&date);
	printaddress(&yield);
	printaddress(&price);

	return 0;
}

void printaddress(void *data)
{
	printf("%p\n", data);
}
