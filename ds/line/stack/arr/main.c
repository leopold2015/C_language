#include <stdio.h>
#include <stdlib.h>

#include "sqstack.h"

int main()
{
	int i = 0;
	datatype arr[] = {19, 23, 34,45, 67};
	sqstack *st;
	datatype tmp;

	st = st_create();
	if(st == NULL)
		exit(1);
	for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		st_push(st, &arr[i]);
	}

	st_travel(st);


	while(st_pop(st, &tmp) == 0)
	{
		//st_pop(st, &tmp);
		printf("POP:%d\n", tmp);
	}


	st_destroy(st);
	

	exit(0);

}
