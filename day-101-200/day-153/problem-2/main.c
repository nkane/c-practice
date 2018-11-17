/*
 * Modify program 13.5 so that the arguments transmitted to both push() and pop() are
 * a structure name rather than a single field variable name.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXCHARS    30
#define DEBUG       0

#define global_variable     static

typedef struct _nameRec
{
    char name[MAXCHARS];
    struct _nameRec *previous;
} NameRec;

global_variable NameRec *GlobalStackPointer;

void
StackPush(NameRec record)
{
    NameRec *newRecord = NULL;

    if (DEBUG)
    {
        printf("Before the push the address in the stack pointer is %p", GlobalStackPointer);
    }

    newRecord = (NameRec *) malloc(sizeof(NameRec));
    if (newRecord == (NameRec *) NULL)
    {
        printf("\nFailed to allocate memory for this structure\n");
    }

    strcpy(newRecord->name, record.name);
    newRecord->previous = GlobalStackPointer;
    GlobalStackPointer = newRecord;

    if (DEBUG)
    {
        printf("\n After the push the address in the stack pointer is %p\n", GlobalStackPointer);
    }
}

void
StackPop(NameRec *popRecord)
{
    NameRec *tempRecord = NULL;

    if (DEBUG)
    {
        printf("Before the pop the address in the stack pointer is %p\n", GlobalStackPointer);
    }

    strcpy(popRecord->name, GlobalStackPointer->name);
    tempRecord = GlobalStackPointer->previous;
    free(GlobalStackPointer);
    GlobalStackPointer = tempRecord;

    if (DEBUG)
    {
        printf("\n After the push the address in the stack pointer is %p\n", GlobalStackPointer);
    }
}

void
ReadPush()
{
    NameRec newRecord = { 0 };

    printf("Enter as many names as you wish, one per line");
    printf("\nTo stop entering names, enter a single x\n");
    while (1)
    {
        printf("Enter a name: ");
        gets(newRecord.name);
        if (strcmp(newRecord.name, "x") == 0)
        {
            break;
        }
        StackPush(newRecord);
    }
}

void
DisplayPop()
{
    NameRec popRecord = { 0 };
    
    printf("\nThe names popped from the stack are:\n");
    while (GlobalStackPointer != NULL)
    {
        StackPop(&popRecord);
        printf("%s\n", popRecord.name);
    }
}

int
main()
{
    GlobalStackPointer = NULL;

    ReadPush();
    DisplayPop();

    return 0;
}
