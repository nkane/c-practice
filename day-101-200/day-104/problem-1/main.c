/*
 * Store the functions IsValidInt() and GetAnInt() provided in this section
 * in a heaer file named datachecks.h. Next, rewrite program 9.9 to use this
 * header file.
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "datachecks.h"

int
main()
{
	int value = 0;

	printf("Enter an integer value: ");
	value = GetAnInt();
	printf("The integer entered is: %d\n", value);

	return 0;
}

