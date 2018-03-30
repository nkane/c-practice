/*
 *  Write a C program that displays the first 8 bits of each character value input into a variable named
 *  ch. (Hint: assuming each character is stored using 8 bits, start by using the hexadecimal mask 80,
 *  which corresponds to the binary number 10000000. If the result of the masking operation is 0; else
 *  display a 1. Then shift the mask one place to the right and examine the next bit, and so on until
 *  all bits in the variable ch have been processed
 *
 */

#include <stdio.h>
#include <stdint.h>

int
main()
{
    uint8_t charMask;
    char ch = ' ';

    printf("Keep entering in characters to get their binary value (or ! to quit):\n");

    while (1)
    {
        charMask = 0x80;
        ch = getchar();
        getchar();

        if (ch == '!') 
        {
            break;
        }

        uint8_t bits = 8;
        uint8_t v;
        printf("%c - bits: ", ch);
        while (bits > 0)
        {
            v = (charMask & ch);
            charMask = (charMask >> 1);
            if (v > 0)
            {
                printf("1");
            }
            else 
            {
                printf("0");
            }
            bits--;
        }
        printf("\n");
    }

    return 0;
}
