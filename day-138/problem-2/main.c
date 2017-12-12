/*
 * Write a C function named trimrear() that deletes all trailing blanks from a string.
 * Write the function using pointers.
 *
 */

#include <stdio.h>

#define SIZE 256

#define len(array)(sizeof(array)/sizeof(array[0]))

void
TrimRear(char *stringBuffer, int stringSize);

int
StringLength(char *stringBuffer, int totalSize);

void
PrintBlanks(char *stringBuffer);

int
main()
{
    char testCaseOne[SIZE] = "this is a test case.   ";
    printf("before trim: ");
    PrintBlanks(testCaseOne);
    TrimRear(testCaseOne, StringLength(testCaseOne, len(testCaseOne)));
    printf("after  trim: ");
    PrintBlanks(testCaseOne);

    char testCaseTwo[SIZE] = "this is a test case.";
    printf("before trim: ");
    PrintBlanks(testCaseTwo);
    TrimRear(testCaseTwo, StringLength(testCaseTwo, len(testCaseTwo)));
    printf("after  trim: ");
    PrintBlanks(testCaseTwo);

    char testCaseThree[SIZE] = "this is a test case. ";
    printf("before trim: ");
    PrintBlanks(testCaseThree);
    TrimRear(testCaseThree, StringLength(testCaseThree, len(testCaseThree)));
    printf("after  trim: ");
    PrintBlanks(testCaseThree);

    return 0;
}

void
TrimRear(char *stringBuffer, int stringSize)
{
    int i;
    for (i = stringSize - 2; *(stringBuffer + i) == ' '; --i);
    *(stringBuffer + (i + 1)) = '\0';
}

int
StringLength(char *stringBuffer, int totalSize)
{
    int i;
    for (i = 0; *(stringBuffer + i) != '\0' && i < totalSize; ++i);
    return i + 1;
}

void
PrintBlanks(char *stringBuffer)
{
   int i = 0;
   char c;
   while ((c = *(stringBuffer + i)) != '\0')
   {
       if (c == ' ')
       {
           printf("_");
       }
       else
       {
           printf("%c", c);
       }
       ++i;
   } 
   printf("\n");
}


