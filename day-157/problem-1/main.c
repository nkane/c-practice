/*
 * Write a queue program that accepts a structure consisting of an integer
 * identification number and a floating-point hourly pay rate.
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct _record
{
    int id;
    float rate;
    struct _record *next;
} Record;

void
Enqueue(Record **queueIn, Record **queueOut, Record record)
{
    Record *newRecord = (Record *) malloc(sizeof(Record));
    if (newRecord)
    {
        newRecord->id = record.id;
        newRecord->rate = record.rate;
        newRecord->next = NULL;
        if (*queueIn)
        {
            (*queueIn)->next = newRecord;
            (*queueIn) = newRecord;
        }
        else
        {
            (*queueIn) = newRecord;
            (*queueOut) = newRecord;
        }
    }
}

bool
Dequeue(Record **queueOut, Record *record)
{
    bool result = false;
    if (*queueOut)
    {
        Record *temp = (*queueOut)->next;
        record->id = (*queueOut)->id;
        record->rate = (*queueOut)->rate;
        record->next = (*queueOut)->next;
        free(*queueOut);
        (*queueOut) = temp;
        result = true;
    }
    return result;
}

Record
GetInputRecord()
{
    Record record = (Record)
    {
        .id = 0,
        .rate = 0.0f,
        .next = NULL
    };

    printf("Enter an id: ");
    scanf("%d", &record.id);

    printf("Enter a rate: ");
    scanf("%f", &record.rate);

    return record;
}

int
main()
{
    Record *queueIn = NULL, *queueOut = NULL;
    Record inputRecord = (Record)
    {
        .id = 0,
        .rate = 0.0f,
        .next = NULL
    };

    int input = 0;

    while (1)
    {
        inputRecord = (Record)
        {
            .id = 0,
            .rate = 0.0f,
            .next = NULL
        };
        inputRecord = GetInputRecord();
        Enqueue(&queueIn, &queueOut, inputRecord);
        printf("Add another record? (1 [y] / 0 [n])");
        scanf("%d", &input);
        if (input == 0)
        {
            break;
        }
    }

    Record outputRecord = (Record)
    {
        .id = 0,
        .rate = 0.0f,
        .next = NULL
    };

    while (Dequeue(&queueOut, &outputRecord))
    {
        printf("id: %d\n", outputRecord.id);
        printf("rate: %6.2f\n", outputRecord.rate);
    }

    return 0;
}
