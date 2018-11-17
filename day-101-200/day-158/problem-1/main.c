/*
 * Add a menu function to Program 13.6 that gives the user a choice of adding a name to
 * the queue, removing a name from the queue, or listing the contents of the queue without
 * removing any structures from it.
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

// Globals
Record *queueIn, *queueOut;

void
Enqueue(char *name)
{
    Record *newRecord = (Record *) malloc(sizeof(Record));
    if (newRecord)
    {
        if (queueOut == NULL)
        {
            queueOut = newRecord;
        }
        if (queueIn != NULL)
        {
            queueIn->next = newRecord;
        }
        strcpy(newRecord->name, name);
        newRecord->next = NULL;
        queueIn = newRecord;
    }
    else
    {
        printf("Error - failed during allocation\n");
    }
}

void
Dequeue(char *name)
{
    Record *tempRecord;
    strcpy(name, queueOut->name);
    tempRecord = queueOut->next;
    free(queueOut);
    queueOut = tempRecord;
}

void
Peek(Record *out, char *name)
{
    strcpy(name, out->name);
}

void
ReadEnqueue()
{
    char name[MAXCHARS];
    printf("Enter as many names as you wish, one per line\nTo stop entering names, enter a single x\n");
    while (1)
    {
        printf("Enter a name: ");
        gets(name);
        if (strcmp(name, "x") == 0)
        {
            break;
        }
        Enqueue(name);
    }
}

void
DequeueDisplay()
{
    char name[MAXCHARS];
    printf("\nThe names dequeued from the queue are:\n");
    while (queueOut)
    {
        Dequeue(name);
        printf("%s\n", name);
    }
}


void
PeekDisplayAll()
{
    Record *out = queueOut;
    while (out)
    {
        printf("Peek: %s\n", out->name);
        out = out->next;
    }
}

int
main()
{
    queueIn = NULL;
    queueOut = NULL;
    char input = '\0';
    char buffer[2];

    do
    {
        printf("Choose an option:\n[a] add to queue\n[d] display first item in queue\n[r] remove single from queue\n[w] display all items in queue\n[x] remove and display all items in queue\n[q] quit\n");
        scanf("%c", &input);
        gets(buffer);
        input = tolower(input);
        switch (input)
        {
            case 'a':
            {
                ReadEnqueue();
            } break;

            case 'd':
            {
                char name[MAXCHARS];
                Peek(queueOut, name);
                printf("Peek: %s\n", name);
            } break;

            case 'r':
            {
                char name[MAXCHARS];
                Dequeue(name);
                printf("Dequeue: %s\n", name);
            } break;

            case 'w':
            {
                PeekDisplayAll();
            } break;

            case 'x':
            {
                DequeueDisplay();
            } break;

            case 'q':
            {
                if (queueIn || queueOut)
                {
                    DequeueDisplay();
                }
            } break;

            default:
            {
                printf("invalid parameter!\n");
            } break;
        }
    } while (input != 'q');
    
    return 0;
}


