#include <stdio.h>
#include <lib/lists.c>

int
main()
{
	List *list = List_Create();
	int x[5] = { 1, 2, 3, 4, 5, };
	for (int i = 0; i < 5; i++)
	{
		List_Insert(list, (x + i));
	}
	List_Print(list);
	List_Delete_At_Index(list, 2);
	List_Print(list);
	List_Insert_At_Index(list, (x + 2), 2);
	List_Print(list);
	List_Destroy(list);
	return 0;
}
