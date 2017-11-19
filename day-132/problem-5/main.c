/*
 * Write a program that stores the following leters in the array named message:
 * This is a test. Have your program copy the data stored in message to another
 * array named mess2 and then display the letters in the mess2 array.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

int
main()
{
	char message[] = "This is a test.";
	char tempMessage[16] = { 0 };
	char *srcPtr, *destPtr;

	for (srcPtr = message, destPtr = tempMessage; srcPtr < (message + len(message)); srcPtr++, destPtr++)
	{
		*destPtr = *srcPtr;
	}
	++destPtr;
	*destPtr = '\0';

	for (srcPtr = tempMessage; srcPtr < (tempMessage + len(tempMessage)); srcPtr++)
	{
		printf("%c", *srcPtr);
	}

	return 0;
}
