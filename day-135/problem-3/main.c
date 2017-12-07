/*
 * Write a program that stores the string "Hooray for All of Us" in an array
 * named strng. Use the declaration char strng[] = "Hooray for All of Us";, which
 * ensures that the end-of-string escape sequence \0 is included in the array. Display
 * the characters in the array by changing the address in a pointer called messPtr.
 * Use a for statement in you program.
 *
 * Modify the program written to use the while statement while (*messPtr != '\0').
 *
 * Modify the program written to start the display with the word All.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

int
main()
{
    char stringBuffer[] = "Hooray for All of Us";
    char *messagePtr = NULL;

    printf("for statement:\n");
    for (messagePtr = stringBuffer;
         messagePtr < (stringBuffer + len(stringBuffer));
         messagePtr++)
    {
        printf("%c", *messagePtr);
    }

    printf("\nwhile statement:\n");
    messagePtr = stringBuffer;
    while (messagePtr < (stringBuffer + len(stringBuffer)))
    {
        printf("%c", *messagePtr++);
    }

    printf("\nSet to all:\n");
    // set to beginning of "All"
    messagePtr = (stringBuffer + 11);
    while (messagePtr < (stringBuffer + len(stringBuffer)))
    {
        printf("%c", *messagePtr++);
    }

    return 0;
}
