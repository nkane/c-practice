/*
 * Repeat the programming exercise 2 in section 8.2, but use pointer
 * references to access all array elements.
 *
 * A) Write a declaration to store the string "This is a test" into an array named
 *    strtest. Include the declaration in a program to display the message using the
 *    following loop:
 *    	for (i = 0; i <= 14; i++)
 * 		printf("%c", strtest[i]);
 *
 * B) Modify the for statement to display only the array characters t, e, s, and t.
 *
 * C) Include the array declaration written in a program that uses the printf() function
 *    to display characters in the array. For example, the statement printf("%s", strtest);
 *    will cause the string stored in the strtest array to be displayed. Using this
 *    statement requires that the last character in the array be the end-of-string marker \0
 *
 * D) Repeat this exercise using a while loop.
 *
 */

#include <stdio.h>
#include <string.h>

int
main()
{
	char *stringBuffer = "This is a test";
	int i;
	int len = strlen(stringBuffer);

	for (i = 0; i < len; ++i)
	{
		printf("%c", *(stringBuffer + i));
	}
	printf("\n");

	for (i = 10; i < len; ++i)
	{
		printf("%c", *(stringBuffer + i ));
	}
	printf("\n");


	printf("%s", stringBuffer);
	printf("\n");

	i = 0;
	while (i < len)
	{
		printf("%c", *(stringBuffer + i));
		++i;
	}
	
	return 0;
}
