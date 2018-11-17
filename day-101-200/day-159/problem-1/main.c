/*
 * Write a program for deleting an existing structure from a linked list of structures 
 * created by program 13.7
 *
 */

#include <stdio.h>
#include <string.h>

#define MAXCHARS 30

typedef struct _record
{
    char name[MAXCHARS];
    struct _record *next;
} Record;

Record *
Locate(Record *list, char *name)
{
    Record *one, *two;
    one = list;
    two = one->next;
    if (two == NULL)
    {
        return one;
    }
    while (1)
    {
        if (strcmp(name, two->name) == 0)
        {
            break;
        }
        else if (two->next = NULL)
        {
            one = two;
            break;
        }
        else
        {
            one = two;
            two = one->next;
        }
    }
    return one;
}

void
Insert(Record **list, char *name)
{
    Record *newRecord = (Record *) malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    newRecord->next = NULL;
    if (newRecord)
    {
        if (*list)
        {
            if (strcmp(name, (*list)->name) < 0)
            {
                newRecord->next = *list;
                *list = newRecord;
            }
            else
            {
                Record *temp = Locate(*list, name);
                newRecord->next = temp->next;
                temp->next = newRecord;
            }
        }
        else 
        {
            *list = newRecord;
        }
    }
    else
    {
        printf("Error - failed to allocate memory!\n");
    }
}

// TODO(nick): wasn't able to finish this!
// there is still a seg fault here! finished up on day 160!
void
Delete(Record *list, char *name)
{
    Record *prior, *found;
    found = list;
    prior = list;
    while (found)
    {
        if (strcmp(found->name, name) == 0)
        {
            Record *next = found->next;
            printf("Freeing %s ...\n", found->name);
            free(found);
            prior->next = next;
            break;
        }
        prior = found;
        found = found->next;
    }
}

void
ReadInsert(Record **list)
{
    char name[MAXCHARS];
    printf("\nEnter as many names as you wish, one per line\nTo stop entering names, enter a single x\n");
    while (1)
    {
        gets(name);
        if (strcmp(name, "x") == 0)
        {
            break;
        }
        Insert(list, name);
    }
}

void
DisplayList(Record *list)
{
    Record *contents;
    contents = list;
    printf("\nThe names currently in the list, in alphabetical\nroder, are:\n");
    while (contents)
    {
        printf("%s\n", contents->name);
        contents = contents->next;
        Delete(list, contents->name);
    }
}

int
main()
{
    Record *list = NULL;

    ReadInsert(&list);
    DisplayList(list);

    return 0;
}
