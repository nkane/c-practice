/*
 * Enter, compile, and execute a program on your computer
 * to determine how many bytes of storage your computer
 * allocates for each of C's data types.
 */

#include <stdio.h>

int main(void)
{
	printf("Data Type		Bytes\n");
	printf("---------		-------\n");
	printf("char			  %zd\n", sizeof(char));
	printf("short int		  %zd\n", sizeof(short int));
	printf("int			  %zd\n", sizeof(int));
	printf("long int		  %zd\n", sizeof(long int));
	printf("float			  %zd\n", sizeof(float));
	printf("double			  %zd\n", sizeof(double));
	printf("long double		  %zd\n", sizeof(long double));

	return 0;
}
