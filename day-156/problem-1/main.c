/*
 * Modify program 13.6 so that the arguments to both enque and dequeue
 * are a structure name rather than a single field varible.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXCHARS 30
#define DEBUG    0

typedef struct _nameRecord
{
    char name[MAXCHARS];
    struct _nameRecord *next;
} NameRecord;

NameRecord *queueIn, *queueOut; 

void
Enqueue(NameRecord record)
{
    NameRecord *newRecord = (NameRecord *) malloc(sizeof(NameRecord));
    
    if (newRecord)
    {
        if (DEBUG)
        {
            printf("Before the enqueue the address in queueIn is %p\nand the address in queueOut is %p", queueIn, queueOut);
        }

        if (queueOut == NULL)
        {
            queueOut = newRecord;
        }

        if (queueIn != NULL)
        {
            queueIn->next = newRecord;
        }
        strcpy(newRecord->name, record.name);
        newRecord->next = NULL;
        queueIn = newRecord;

        if (DEBUG)
        {
            printf("After the enqueue the address in queueIn is %p\nand the address in queueOut is %p", queueIn, queueOut);
        }
    }
    else
    {
        printf("Error allocating memory for name record\n");
    }
}

void
Dequeue(NameRecord *result)
{
    NameRecord *record;
    if (DEBUG)
    {
        printf("Before the dequeue the address in queueIn is %p\nand the address in queueOut is %p", queueIn, queueOut);
    }

    strcpy(result->name, queueOut->name);
    record = queueOut->next;
    free(queueOut);
    queueOut = record;

    if (DEBUG)
    {
        printf("After the dequeue the address in queueIn is %p\nand the address in queueOut is %p", queueIn, queueOut);
    }
}

void
ReadEnqueue()
{
    NameRecord record = (NameRecord)
    {
        .name = 0,
        .next = 0
    };
    printf("Enter as many names as you wish, one per line\nTo stop entering names, enter a single x\n");
    while (1)
    {
        printf("Enter a name: ");
        gets(&record.name);
        if (strcmp(record.name, "x") == 0)
        {
            break;
        }
        Enqueue(record);
    }
}

void
DequeueShow()
{
    NameRecord record = (NameRecord)
    {
        .name = 0,
        .next = 0
    };
    printf("\nThe names dequeued from the queue are:\n");
    while (queueOut != NULL)
    {
        Dequeue(&record);
        printf("%s\n", record.name);
    }
}

int
main()
{
    queueIn = NULL;
    queueOut = NULL;

    ReadEnqueue();
    DequeueShow();

    return 0;
}
