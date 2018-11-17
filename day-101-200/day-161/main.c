/*
 * Write a function named modify() that can be used to modify the name member of the structure
 * created in Program 13.7. The arguments passed to modify should be the address of the structure
 * to be modified. The modify function should first display the existing name in the selected
 * structure and then request new data for this member.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHARS    30
#define DEBUG        0

typedef struct _nameRecord
{
    char Name[MAXCHARS];
    struct _nameRecord *Next;
} NameRecord;

void
ReadInsert();

void
Insert(char *name);

NameRecord *
Locate(char *name);

void
Modify(NameRecord *record);

void
Display();

NameRecord *list;

int
main()
{
    list = NULL;
    char c = 'y';
    while (c != 'x')
    {
        printf("Type x to exit\n");
        printf("Insert or modify (i / m):\n");
        printf("To Display (d):\n");
        c = getchar();
        getchar();
        c = tolower(c);
        switch (c)
        {
            case 'i':
            {
                ReadInsert();
            } break;

            case 'm':
            {
                // find node firs
                char b[MAXCHARS];
                printf("Enter in the name to modify:\n");
                gets(b);
                NameRecord *record = Locate(b);
                if (record != NULL)
                {
                    Modify(record);
                }
                else
                {
                    printf("Unable to locate: %s\n", b);
                }
            } break;

            case 'd':
            {
                Display();
            } break;

            case 'x':
            { 
                Display();
                printf("exiting\n");
            } break;

            default:
            {
                printf("No action taken ...\n");
            } break;
        }
    }

    return 0;
}

void
ReadInsert()
{
    char name[MAXCHARS];
    printf("\nEnter as many names as you wish, one per line:");
    printf("\nTo stop entering names, enter a single x\n");
    while (1)
    {
        printf("Enter a name: ");
        gets(name);
        if (strcmp(name, "x") == 0)
        {
            break;
        }
        Insert(name);
    }
}

void
Insert(char *name)
{
    NameRecord *newRecord;

    newRecord = (NameRecord *)malloc(sizeof(NameRecord));
    if (newRecord == NULL)
    {
        printf("\nError: Could not allowcate the requested space\n");
        exit(1);
    }

    if (list == NULL)
    {
        newRecord->Next = NULL;
        list = newRecord;
    }
    else if (strcmp(name, list->Name) < 0)
    {
        newRecord->Next = list;
        list = newRecord;
    }
    else 
    {
        NameRecord *insertionSlot = Locate(name);
        newRecord->Next = insertionSlot->Next;
        insertionSlot->Next = newRecord;
    }
    strcpy(newRecord->Name, name);
}

NameRecord *
Locate(char *name)
{
    NameRecord *one, *two;
    one = list;
    two = list->Next;

    if (two == NULL)
    {
        return one;
    }

    while (1)
    {
        if (strcmp(name, two->Name) < 0)
        {
            break;
        }
        else if (two->Next == NULL)
        {
            one = two;
            break;
        }
        else
        {
            one = two;
            two = one->Next;
        }
    }

    return one;
}

void
Modify(NameRecord *record)
{
    char b[MAXCHARS];
    printf("Existing Node at address: 0x%x\n", (unsigned int)record);
    printf("Data -> Name: %s\n", record->Name);
    printf("Enter in a new name to replace: ");
    gets(b);
    strcpy(record->Name, b);
}

void
Display()
{
    NameRecord *contents;
    contents = list;
    printf("\nThe names currently in the list, in alphabetical\norder, are:\n");
    while (contents != NULL)
    {
        printf("%s\n", contents->Name);
        contents = contents->Next;
    }
}
