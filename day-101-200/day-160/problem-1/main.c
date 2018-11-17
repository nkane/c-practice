/*
 * NOTE(nick): continuation from day-159
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
    Record *node = NULL;
    if (strcmp(list->name, name) < 0)
    {
        node = list;
        Record *prior = list;
        while (node->next)
        {
            if (strcmp(node->name, name) > 0)
            {
                node = prior;
                break;
            }
            prior = node;
            node = node->next;
        }
    }
    return node;
}

void
Insert(Record **list, char *name)
{
    Record *newRecord = (Record *) malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    newRecord->next = NULL;
    if (*list)
    {
        // find proper insertion position
        Record *node = Locate(*list, name);
        // make new record head and the prior head connected
        if (node == NULL)
        {
            node = *list;
            *list = newRecord;
            (*list)->next = node;
        }
        else
        {
            if (node->next)
            {
                newRecord->next = node->next;
                node->next = newRecord;
            }
            else
            {
                node->next = newRecord;
            }

        }
    }
    else
    {
        *list = newRecord;
    }
}

void
Delete(Record *list, char *name)
{
    unsigned char deleted = 0;
    Record *node = list;
    Record *prior = list;
    while (node)
    {
        if (strcmp(node->name, name) == 0)
        {
            printf("Removing %s from list\n", name);
            if (node->next)
            {
                Record *nextNode = node->next;
                prior->next = nextNode;
                free(node);
            }
            else
            {
                free(node);
                prior->next = NULL;
            }
            deleted = 1;
            break;
        }
        prior = node;
        node = node->next;
    }

    if (deleted == 0)
    {
        printf("Cannot find %s in list\n", name);
    }
}

int
main()
{
    Record *list = NULL;

    Insert(&list, "nick");
    Insert(&list, "mike");
    Insert(&list, "jess");
    Insert(&list, "roger");
    Insert(&list, "larry");

    Delete(list, "katie");
    Delete(list, "roger");
    Delete(list, "larry");

    return 0;
}
