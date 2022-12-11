#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main()
{
	int i = 0;
	list * l = NULL;
	datatype arr[] = {12,89,23,25, 34,45};
	int value = 12;
	int delvalue = 0;
	int err = 0;
	int index = 0;
	int findvalue = 0;
	int findvalue1 = 0;

	l = list_create();
	if(l == NULL)
	{
		exit(1);
	}
	for(i  = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		//if(list_insert_at(l, 0, &arr[i]))
		if(list_order_insert(l, &arr[i]))
		{
			exit(1);
		}
	}

	list_display(l);

	list_delete(l, &value);
		
	list_display(l);

	err = list_delete_at(l, 3, &delvalue);
	if(err)
		exit(1);
	printf("delvalue = %d\n", delvalue);
	list_display(l);
	
	list_find_at(l, 3, &findvalue);
	printf("findvalue:%d\n", findvalue);
	findvalue1 = 34;
	list_find_place(l, &findvalue1, &index);
	printf("index:%d\n", index);


	list_destroy(l);

	exit(0);

}
