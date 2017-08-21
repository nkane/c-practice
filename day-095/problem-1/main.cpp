/*
 * The following function can be used to select and display all vowels contained
 * within a user-input string:
 *
 * void vowels(char string[])
 * {
 * 	int i = 0;
 * 	char c;
 *
 * 	while ((c = string[i++]) != '\0')
 * 	{
 * 		switch (c)
 * 		{
 * 			case 'a':
 * 			case 'e':
 * 			case 'i':
 * 			case 'o':
 * 			case 'u':
 * 				putchar(c);
 * 		}
 * 	}
 * 	putchar('\n');
 * }
 *
 * Noitce that the switch statement in vowels() uses the fact that selected cases "drop through"
 * in the absence of break statements. Thus, all selected cases result in a putchar() function
 * call. Include vowels() in a working progrma that accepts a user-input string and then displays
 * all vowels in the string. In response to the input How much is the little worth worth?, your
 * program should display ouieieoo.
 *
 * Modify the vowels() function to cound and display the total number of vowels contained in the string
 * passed to it.
 *
 */

#include <stdio.h>

int
main()
{
	return 0;
}

