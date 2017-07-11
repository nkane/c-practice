/*
 * Write declartion statments to store the string of characters "Input
 * the Following Data" in a character array named message1, the string
 * "------------------" in the array named message2, the string "Enter
 * the date: " in the array message3, and the string "Enter the account
 * number: " in the array named message4.
 *
 * Display all the above messages in console output.
 *
 */

#include <stdio.h>

int
main()
{
	char message1[] = "Input the following data: \0";
	char message2[] = "------------------------------\0";
	char message3[] = "Enter the data: \0";
	char message4[] = "Enter the account number: \0";
	
	printf("%s\n", message1);
	printf("%s\n", message2);
	printf("%s\n", message3);
	printf("%s\n", message4);

	return 0;
}
