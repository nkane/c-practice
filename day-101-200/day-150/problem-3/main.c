/*
 * Modify Program 13.3 to prompt the user for a name. Have the program search the existing
 * list for the entered name. If the name is in the list, display the corresponding phone
 * number; otherwise, display the message: The name is not in the current phone directory.
 *
 */

#include <stdbool.h>
#include <stdio.h>

#define MAXNAME     30
#define MAXPHONE    15

typedef struct _teleType
{
    char name[MAXNAME];
    char phoneNum[MAXPHONE];
    struct _teleType *next;
} TeleType;

void
DisplayAll(TeleType *head);

void
FindPerson(TeleType *head, char *name);

int
main()
{
    TeleType t1 =
    {
        "Acme, Sam",
        "(555) 898-2392",
        NULL,
    };

    TeleType t2 =
    {
       "Dolan, Edith",
       "(555) 682-3104",
        NULL,
    };

    TeleType t3 =
    {
        "Lanfrank, John",
        "(555) 718-4581",
        NULL,
    };

    TeleType *head = NULL;

    head = &t1;
    t1.next = &t2;
    t2.next = &t3;
    t3.next = NULL;

    DisplayAll(head);

    char tempName[MAXNAME] = { 0 };
    printf("Enter exact search name:");
    gets(tempName);

    FindPerson(head, tempName);

    return 0;
}

void
DisplayAll(TeleType *head)
{
    TeleType *contents = head;
    while (contents != NULL)
    {
        printf("%-30s %-20s\n", contents->name, contents->phoneNum);
        contents = contents->next;
    }
}

void
FindPerson(TeleType *head, char *name)
{
    TeleType *contents = head;
    bool found = false;
    while (contents != NULL)
    {
        if (strcmp(name, contents->name) == 0)
        {
            found = true;
            break;
        }
        contents = contents->next;
    }
    if (found)
    {
        printf("%-30s %-20s\n", contents->name, contents->phoneNum);
    }
    else
    {
        printf("The name is not in the current phone directory.");
    }
}
