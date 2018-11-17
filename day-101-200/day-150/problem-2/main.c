/*
 * Enter and execute Program 13.2
 *
 */

#include <stdio.h>

#define MAXNAME     30
#define MAXPHONE    15

typedef struct _teleType
{
    char name[MAXNAME];
    char phoneNumber [MAXPHONE];
    struct _teleType *next;
} TeleType;

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
    head->next = &t2;
    head->next->next = &t3;
    head->next->next->next = NULL;

    printf("%s\n%s\n%s\n", head->name, head->next->name, head->next->next->name);

    return 0;
}
