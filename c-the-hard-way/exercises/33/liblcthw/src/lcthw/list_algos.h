#ifndef lcthw_List_algos_h
#define lcthw_List_algos_h

#include <lcthw/list.h>

typedef int (*List_compare)(const void *s1, const void *s2);

int
List_Bubble_Sort(List *list, List_compare list_compare_function);

List *
List_Merge_Sort(List *list, List_compare list_compare_function);

#endif
