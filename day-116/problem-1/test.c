#include <assert.h>

#include "list.c"
	
	
void
test_case_one()
{
	LinkList l;
	NewList(&l, sizeof(int), NULL);
	int x = 20;
	int y = 30;

	Insert(&l, &x);
	Insert(&l, &y);

	x = 100;
	y = 500;

	Insert(&l, &x);
	Insert(&l, &y);

	Node *test = l.Head;
	int i = 0;
	int *checkValue;
	while (test != NULL)
	{
		checkValue = (int *)test->Value;
		switch (i)
		{
			case 0:
			{
				assert(*checkValue == 20);
			} break;

			case 1:
			{
				assert(*checkValue == 30);
			} break;

			case 2:
			{
				assert(*checkValue == 100);
			} break;

			case 3:
			{
				assert(*checkValue == 500);
			} break;

			default:
			{
				assert(0 == -1);
			} break;
		}
		test = test->Next;
		++i;
	}

	FreeList(&l);
}
