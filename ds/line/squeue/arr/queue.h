#ifndef SQUEUE_H__
#define SQUEUE_H__

#define MAXSIZE 6
typedef int datatype;

typedef struct node_st
{
	datatype data[MAXSIZE];
	int head, tail;
}queue;


queue *qu_create();

int qu_isempty(queue *);

int qu_enqueue(queue *, datatype *);

int qu_dequeue(queue *, datatype *);

int qu_travel(queue *);

void qu_clear(queue *);


void qu_destroy(queue *);





#endif
