#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

queue *qu_create()
{
	queue *sq;

	sq = malloc(sizeof(*sq));
	if(sq == NULL)
		return NULL;

	sq->head = 0;
	sq->tail = 0;

	return sq;

}

int qu_isempty(queue *sq)
{
	return (sq->head == sq->tail);
	
}

int qu_enqueue(queue *sq, datatype *x)
{
	if((sq->tail + 1) % MAXSIZE == sq->head)
		return -1;

	sq->tail = (sq->tail + 1) % MAXSIZE;
	sq->data[sq->tail] = *x;

	return 0;
}

int qu_dequeue(queue *sq, datatype *x)
{
	if(qu_isempty(sq))
		return -1;
	
	sq->head = (sq->head + 1) % MAXSIZE;
	*x = sq->data[sq->head];


	return 0;

}

int qu_travel(queue *sq)
{
	int i = 0;
	if(sq->head == sq->tail)
		return -1;

	i = (sq->head + 1)%MAXSIZE;
	while(i != sq->tail)
	{
		printf("%d ", sq->data[i]);
		i = (i + 1) % MAXSIZE;
	
	}
	printf(" %d \n",sq->data[i]);
	
	return 0;
}

void qu_clear(queue *sq)
{
	sq->head = sq->tail;
	
}


void qu_destroy(queue *sq)
{
	free(sq);
}
