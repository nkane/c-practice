/*
 * A bookstore summarizes its monthly transactions by keeping of the following information
 * for each book in stock:
 * - Book indentification number
 * - Inventory balance at the beginning of the month
 * - Number of copies received during the month
 * - Number of coopies sold during the month
 * 
 * Write a C program that accepts this data for each book and then displays the book
 * identification number and an update book inventory balance using the relationship:
 *	+ number of copies received during the month
 * 	- number of copies sold during the month
 *
 * This program should use a while statement with a fixed-count condition, so that 
 * information on only three books is requested.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Fixed_Count = 3;
global_variable int CurrentId = 1;

struct Book
{
	int Id;
	int BeginningMonthInventory;
	int ReceivedCopies;
	int SoldCopies;
};

inline Book
CreateBook();

inline void
PrettyPrint(Book *);

int
main()
{
	Book B;
	for (int i = 0; i < Fixed_Count; ++i)
	{
		B = CreateBook();
		PrettyPrint(&B);
	}

	return 0;
}

inline Book
CreateBook()
{
	Book B = {};

	B.Id = CurrentId;
	++CurrentId;

	printf("Enter in the inventory at the beginning of the month:\n");
	scanf("%d", &B.BeginningMonthInventory);

	printf("Enter in number of copies received during the month:\n");
	scanf("%d", &B.ReceivedCopies);

	printf("Enter in number of copies sold during the month:\n");
	scanf("%d", &B.SoldCopies);

	return B;
}

inline void
PrettyPrint(Book *b)
{
	printf("Book Id: %d\n", b->Id);
	printf("Beginning of month inventory: %d\n", b->BeginningMonthInventory);
	printf("Received copies: %d\n", b->ReceivedCopies);
	printf("Beginning month on-hand copies: %d\n", (b->ReceivedCopies + b->BeginningMonthInventory));
	printf("Sold copies: %d\n", b->SoldCopies);
	printf("Current on-hand copies: %d\n\n", (b->ReceivedCopies + b->BeginningMonthInventory) - b->SoldCopies);
}
