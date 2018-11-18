#include <stdio.h>
#include <lib/lists.c>
#include <lib/queues.c>

int
main()
{
	Queue *queue = Create_Queue();
	int x = 10;
	int y = 20;
	Queue_Enqueue(queue, &x);
	Queue_Enqueue(queue, &y);
	Print_Queue(queue);
	return 0;
}
