#ifndef lcthw_List_algos_h
#define lcthw_List_algos_h

#include <string.h>

typedef int (*List_compare)(const char *s1, const char *s2);

int
List_bubble_sort(List *list, List_compare list_compare_function);

List *
List_merge_sort(List *list, List_compare list_compare_function);

#endif
