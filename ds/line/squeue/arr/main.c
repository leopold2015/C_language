#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
int main()
{
	queue *sq;
	int i = 0;
	datatype arr[] = {12,34,98,23,45};

	sq = qu_create();
	if(sq == NULL)
		exit(1);

	for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
		qu_enqueue(sq, &arr[i]);


	qu_travel(sq);	


	datatype tmp;
	qu_dequeue(sq, &tmp);
	printf("DEQUEUE:%d\n", tmp);
	qu_travel(sq);

	qu_destroy(sq);


	exit(0);
}
