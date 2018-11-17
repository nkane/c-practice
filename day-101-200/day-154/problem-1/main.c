/*
 * Write a stack program that accepts a struture consisting of interger identification
 * numbers and a floating-point hourly pay rate.
 *
 */

#include <stdio.h>

typedef struct _record
{
    int id;
    float rate;
    struct _record *previous;
} Record;

Record
GetInputRecord()
{
    Record result = (Record)
    {
        .id = 0,
        .rate = 0.0f
    };
    
    printf("enter in the ID: ");
    scanf("%d", &result.id);

    printf("enter in the rate: ");
    scanf("%f", &result.rate);

    return result;
}

void
OutputRecord(Record data)
{
    printf("ID: %d\n", data.id);
    printf("Rate: %6.2f\n", data.rate);
}

void
StackPush(Record **stack, Record data)
{
    // check if stack is empty
    if (*stack)
    {
        Record *newRecord = (Record *) malloc(sizeof(Record));
        newRecord->id = data.id;
        newRecord->rate = data.rate;
        newRecord->previous = *stack;
        *stack = newRecord;
    }
    else
    {
        *stack = (Record *) malloc(sizeof(Record));
        (*stack)->id = data.id;
        (*stack)->rate = data.rate;
        (*stack)->previous = NULL;
    }
}

Record
StackPop(Record **stack)
{
    Record result = (Record)
    {
        .id = 0,
        .rate = 0.0f
    };

    if (*stack)
    {
        result.id = (*stack)->id;
        result.rate = (*stack)->rate;
        Record *temp = (*stack)->previous;
        free(*stack);
        *stack = temp;
    }

    return result;
}

int
main()
{
    Record *stack = NULL;
    Record inputRecord = (Record)
    {
        .id = 0,
        .rate = 0.0f
    };

    int stackCount = 0;
    char input = '\0';
    while (1)
    {
        inputRecord = GetInputRecord();
        StackPush(&stack, inputRecord);
        stackCount++;
        printf("Add more record? (y/n)\n");
        scanf("\n%c", &input);
        if (input == 'n')
        {
            break;
        }
    }

    Record outputRecord = (Record)
    {
        .id = 0,
        .rate = 0.0f
    };
    
    while (stackCount > 0)
    {
        outputRecord = StackPop(&stack);
        OutputRecord(outputRecord);
        --stackCount;
    }

    system("pause");

    return 0;
}
