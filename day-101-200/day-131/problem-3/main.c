/*
 * Repeat the programming exercise 1 in section 8.2, but use pointer
 * references to access all array elements.
 *
 * A) Write declaration statements to store the string of characters 
 *    "Input the following Data" in a character array named message1, the
 *    string "---------------" in the array named message2, the string
 *    "Enter the Date:" in the array named message3, and the string
 *    "Enter the Account Number:" in the array message 4
 *
 * B) Include the array declaration written above in a program that uses
 *    printf function to display the messages. For example, the statement
 *    printf("%s", message1); causes the string stored in message1 array
 *    to be displayed. Your program will require four such statements
 *    to display the four individual messages. Using the printf() function
 *    with the %s control sequence to display a string requires that the
 *    end-of-string marker \0 is present in the character array used to store
 *    the stringh.
 *
 */

#include <stdio.h>
#include <string.h>

#define len(array)(sizeof(array)/sizeof(array[0]))


int
main()
{
	char *statements[4] = 
	{
		"Input the following Data",
		"------------------------",
		"Enter the Date: ",
		"Enter the Account Number: "
	};
	int i;

	for (i = 0; i < len(statements); ++i)
	{
		printf("%s\n", *(statements + i));
	}

	return 0;
}
