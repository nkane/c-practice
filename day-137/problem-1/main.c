/*
 * Write a program using the getchar(), toupper(), and putchar() library functions
 * that echo back each letter entered in its uppercase form. The program should terminate
 * when the digit 1 key is pressed.
 *
 */

#include <stdio.h>

int
main()
{
    char c = '\0';
    
    printf("Starting program ...\n");
    do
    {
        c = getchar();
        c = toupper(c);
        if (c != '1')
        {
            putchar(c);
        }
    } while(c != '\0' && c != '1');

    return 0;
}
