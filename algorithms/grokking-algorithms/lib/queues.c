/*
 * 	queue.c
 * 	Created By: Nick Kane
 *
 */

typedef struct _queue
{
	union
	{
		List *list;
	};
} Queue;


Queue *
Create_Queue()
{
	Queue *queue = (Queue *)List_Create();
	return queue;
}

void
Queue_Destroy(Queue *queue)
{
	if (queue)
	{
		free(queue);
	}
}

void
Queue_Enqueue(Queue *queue, void *value)
{
	List_Insert((List *)queue, value);
}

void
Queue_Dequeue()
{
	// TODO(nick)
}

void
Print_Queue(Queue *queue)
{
	List_Print((List *)queue);
}
