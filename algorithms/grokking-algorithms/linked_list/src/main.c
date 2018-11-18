#include <stdio.h>
#include <lib/lists.c>

int
main()
{
	List *l = List_Create();
	int x[5] = { 1, 2, 3, 4, 5, };
	for (int i = 0; i < 5; i++)
	{
		List_Add(l, (x + i));
	}
	List_Print(l);
	List_Remove(l, 2);
	List_Print(l);
	List_Destroy(l);
	return 0;
}
