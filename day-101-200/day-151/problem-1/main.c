/*
 * Write a program containing a linked list of 10 integer numbers. Have the program
 * display the numbers in the list.
 *
 */

#include <stdio.h>

typedef struct _listNode
{
    int value;
    struct _listNode *next;
} ListNode;

ListNode *
NewNode(int value);

void
Insert(ListNode **head, int value);

void
PrintNodes(ListNode *head);

void
RemoveAll(ListNode *head);

int
main()
{
    ListNode *head = NULL;
    //head = NewNode(0);

    for (int i = 0; i < 10; ++i)
    {
        Insert(&head, i);
    }

    PrintNodes(head);

    RemoveAll(head);

    system("pause");

    return 0;
}

ListNode *
NewNode(int value)
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->value = value;
    head->next = NULL;
    return head;
}

void
Insert(ListNode **head, int value)
{
    if (*head)
    {
        // find the last node in the list
        ListNode *currentNode = *head;
        while (currentNode->next)
        {
            currentNode = currentNode->next;
        }
        ListNode *newNode = NewNode(value);
        currentNode->next = newNode;
    }
    else
    {
        *head = NewNode(value);
    }
}

void
PrintNodes(ListNode *head)
{
    if (head)
    {
        ListNode *nodePtr = head;
        while (nodePtr)
        {
            printf("Node value: %d\n", nodePtr->value);
            nodePtr = nodePtr->next;
        }
    }
}

void
RemoveAll(ListNode *head)
{
    if (head)
    {
        ListNode *currentNode = head->next;
        while (head)
        {
            free(head);
            head = currentNode;
            if (head)
            {
                currentNode = head->next;
            }
        }
    }
}
