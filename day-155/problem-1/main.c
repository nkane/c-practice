/*
 * Add a menu function to Program 13.5 that gives the user a choice of adding
 * a name to the stack, removing a name from the stack, or listing
 * the contents of the stack without removing any structures from it.
 *
 */

#include <stdio.h>
#include <string.h>

#define MAXCHARS    30
#define DEBUG       0

typedef struct _nameRecord
{
    char name[MAXCHARS];
    struct _nameRecord *previous;
} NameRecord;

void
StackPush(NameRecord **stack, char *name)
{
    NameRecord *newRecord = NULL;
    if (DEBUG)
    {
        printf("Before the push the address in stack pointer is %p\n", *stack);
    }

    newRecord = (NameRecord *) malloc(sizeof(NameRecord));
    if (newRecord == NULL)
    {
        printf("\nFailed to allocate memory for NameRecord structure\n");
        exit(1);
    }

    strcpy(newRecord->name, name);
    newRecord->previous = *stack;
    *stack = newRecord;
    if (DEBUG)
    {
        printf("\nAfter the push the address in stack pointer is %p\n", *stack);
    }
}

NameRecord
StackPeek(NameRecord *stack)
{
    NameRecord result = { 0 };
    if (stack)
    {
        strcpy(result.name, stack->name);
        result.previous = stack->previous;
    }
    else
    {
        printf("\nFailed to peek record from stack!\n");
    }
    return result;
}

NameRecord
StackPop(NameRecord **stack)
{
    NameRecord result = { 0 };
    NameRecord *tempRecord = NULL;
    if (DEBUG)
    {
        printf("Before the push the address in stack pointer is %p\n", *stack);
    }

    if (stack)
    {
        strcpy(result.name, (*stack)->name);
        result.previous = (*stack)->previous;
        tempRecord = (*stack)->previous;
        free(*stack);
        *stack = tempRecord;
        if (DEBUG)
        {
            printf("\nAfter the push the address in stack pointer is %p\n", *stack);
        }
    }
    else
    {
        printf("\nFailed to pop off record from stack!\n");
    }

    return result;
}

void
ReadPush(NameRecord **stack)
{
    char name[MAXCHARS] = { 0 };

    printf("Enter as many names as you wish, one per line\nTo stop entering the names, enter a single x\n");
    // eat first new line
    gets(name);
    while (1)
    {
        printf("Enter a name: ");
        gets(name);
        if (strcmp(name, "x") == 0)
        {
            break;
        }
        StackPush(stack, name);
    }
}

void
PopDisplay(NameRecord **stack)
{
    NameRecord currentRecord = { 0 };
    printf("\nThe names popped from the stack are:\n");
    while (*stack)
    {
        currentRecord = StackPop(stack);
        printf("%s\n", currentRecord.name);
    }
}

void
PeekDisplay(NameRecord *stack)
{
    NameRecord currentRecord = { 0 };
    printf("\nThe names peeked from the stack are:\n");
    while (stack)
    {
        currentRecord = StackPeek(stack);
        printf("%s\n", currentRecord.name);
        stack = currentRecord.previous;
    }
}

int
main()
{
    NameRecord *stackPointer = NULL;
    char input = '\0';

    do {
        printf("\nStack Menu:\n[a] add record\n[r] remove record\n[p] peek record\n[d] remove all record\n[l] peek all record\n[q] quit\n");
        input = getchar();

        input = tolower(input);
        switch (input)
        {
            case 'a':
            {
                ReadPush(&stackPointer);
            } break;

            case 'r':
            {
                NameRecord removedRecord = StackPop(&stackPointer);
                printf("Removed single record from stack\nName: %s\n\n", removedRecord.name);
            } break;

            case 'p':
            {
                NameRecord peekedRecord = StackPeek(stackPointer);
                printf("Peeked top record from stack\nName: %s\n\n", peekedRecord.name);
            } break;

            case 'd':
            {
                PopDisplay(&stackPointer);
                printf("\n");
            } break;

            case 'l':
            {
                PeekDisplay(stackPointer);
                printf("\n");
            } break;
        }
    } while (input != 'q');

    if (stackPointer)
    {
        PopDisplay(&stackPointer);
        printf("\n");
    }

    system("pause");

    return 0;
}
