/*
 * A doubly linked list is a list in which each structure contains a pointer to both the
 * following and previous structures in the list. Define an appropriate template for a
 * doubly linked list of names and telephone numbers.
 *
 * Using the template defined in a previous exercise, modify the program to list the
 * names and phone numbers in reverse order.
 *
 */

#include <stdio.h>

#define NAME_MAX    30
#define PHONE_MAX   15

typedef enum _ordering
{
    NONE     = 0x00,
    STANDARD = 0x01,
    REVERSE  = 0x02,
} Ordering;

typedef struct _listNode
{
    char name[NAME_MAX];
    char phoneNumber[PHONE_MAX];
    struct _listNode *next;
    struct _listNode *previous;
} ListNode;

typedef struct _list
{
    ListNode *head;
    ListNode *tail;
} List;

void
AddNode(List *list, char name[30], char phoneNumber[15])
{
    if (list)
    {
        ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
        strcpy(newNode->name, name);
        strcpy(newNode->phoneNumber, phoneNumber);
        newNode->next = NULL;
        newNode->previous = NULL;
        if (list->head == NULL)
        {
            list->head = newNode;
            list->tail = newNode;
        }
        else
        {
            ListNode *tempPreviousNode = list->tail;
            tempPreviousNode->next = newNode;
            list->tail = newNode;
            list->tail->previous = tempPreviousNode;
            list->tail->next = NULL;
        }
    }
}

void
PrintListByOrder(List *list, int order)
{
    ListNode *startingNode = NULL;
    switch (order)
    {
        case REVERSE:
        {
            startingNode = list->tail;
            while (startingNode)
            {
                printf("%-30s %-20s\n", startingNode->name, startingNode->phoneNumber);
                startingNode = startingNode->previous;
            }
        } break;
        
        default:
        {
            startingNode = list->head;
            while (startingNode)
            {
                printf("%-30s %-20s\n", startingNode->name, startingNode->phoneNumber);
                startingNode = startingNode->next;
            }
        } break;
    }
}

void
RemoveAll(List *list)
{
    ListNode *temp = list->head;
    while (temp)
    {
        temp = list->head->next;
        printf("freeing %s -> number: %s\n", list->head->name, list->head->phoneNumber);
        free(list->head);
        list->head = temp;
    }
    list->head = NULL;
    list->tail = NULL;
}

int
main()
{
    List list = (List)
    {
        .head = NULL,
        .tail = NULL
    };

    AddNode(&list, "John Doe", "333-253-6143");
    AddNode(&list, "Jan Doe", "333-432-1113");
    AddNode(&list, "Mike Tyson", "333-665-3321");

    printf("Printing by tail ... reverse\n");
    PrintListByOrder(&list, REVERSE);

    printf("Printing by head ... standard\n");
    PrintListByOrder(&list, STANDARD);

    RemoveAll(&list);

    return 0;
}
