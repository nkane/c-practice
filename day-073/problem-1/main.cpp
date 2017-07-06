/*
 * A numeric palindrome is a number that is the same when read either
 * forward or backward. For example, the number 4321234 is a numeric
 * palindrome. Use this information to create a recursive function named
 * numpal() that accepts an integer number as a parameter and returns 1
 * if the parameter is a numeric palindrome and 0 if it is not.
 *
 */

#include <stdio.h>
#include <math.h>

int
isPalindrome(int num);

int 
reverse(int num);

int
main()
{
	int x = 4321234;
	int y = 1034;

	int testOne = isPalindrome(x);
	int testTwo = isPalindrome(y);

	return 0;
}


// NOTE(nick): was stumped again on this problem
// used following source for help / source code:
// http://www.codeforwin.in/2016/03/c-program-to-check-palindrome-number-using-recursion.html

int
isPalindrome(int num)
{
	if (num == reverse(num))
	{
		return 1;
	}
	return 0;
}

int 
reverse(int num)
{
	int digit;
	
	if (num == 0)
	{
		return 0;
	}

	// total number of digits
	digit = (int)log10(num);

	return (num % 10 * pow(10, digit) + reverse(num / 10));
}
