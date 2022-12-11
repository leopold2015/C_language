#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list *list_create()
{
	list *me;
	me = malloc(sizeof(*me));
	if(me == NULL)
	{
		return NULL;
	}
	me->next = NULL;
	return me;
}

int list_insert_at(list *me, int i, datatype *data)
{
	int j = 0;
	
	list *node = me, *newnode = NULL;

	if(i < 0)
		return -1;
		// return -EINVAL;

	while(j < i  && node != NULL)
	{
		node = node->next;
		j++;

	}

	if(node)
	{
		newnode = malloc(sizeof(*newnode));
		if(newnode == NULL)
			return -2;
		newnode->data  = *data;
		//newnode->next = NULL;

		newnode->next = node->next;
		node->next = newnode;

		return 0;
	}
	else
	{
		return -3;
	}


}

int list_order_insert(list *me, datatype *data)
{
	list *p = me, *q;
	while(p->next && p->next->data < *data)
		p = p->next;
	q = malloc(sizeof(*q));
	if(q == NULL)
		return -1;

	q->data = *data;
	q->next = p->next;
	p->next = q;

	return 0;
}

int list_delete(list *me, datatype *data)
{
	list *p = me, *q = NULL;

	q = malloc(sizeof(*q));
	if(q == NULL)
		return -1;

	while(p->next && p->next->data != *data)
		p = p->next;

	if(p->next == NULL)
		return -1;
	else
	{
		q = p->next;
		p->next = q->next;
		free(q);
		q = NULL;
	}

	return 0;
}

int list_delete_at(list *me, int i, datatype *data)
{
	int j = 0;
	list *p = me, *q = NULL;
	
	*data = -1;

	q = malloc(sizeof(*q));
        if(q == NULL)
                return -1;
	
	while(j < i && p)
	{
		p = p->next;
		j++;
	}
	printf("p-next-data:%d\n", p->next->data);
	if(p != NULL)
	{	
		*data = p->next->data;
		q = p->next;
		p->next = q->next;
		free(q);
		q = NULL;	
	}

	return 0;
}

int list_isempty(list *me)
{
	if(me->next == NULL)
	{
		return 0;
	}
	return 1;
}

int list_find_place(list *me,  datatype *data, int *place)
{
	list *p = me;
	int j = 0;

	while(p && p->next->data != *data)
	{
		j++;
		p = p->next;
	}

	if(p != NULL)
	{
		*place = j;
	}
	else
	{
		return -1;
	}

	return 0;
}

int list_find_at(list *me, int i, datatype *data)
{
	list *p = me;
	int j = 0;	
		
	*data = -1;

	while(p && j < i)
	{
		p = p->next;
		j++;
	} 	
	
	if(p)
	{
		*data = p->next->data;
	}
	else
	{
		return -1;
	}	

	return 0;
}

void list_display(list *me)
{
	list *node = me->next;
	if(list_isempty(me) == 0)
		return;
	while(node != NULL)
	{
		printf("%d->",node->data);
		node = node->next;
	}
	printf("null\n");

	return ;
}
void list_destroy(list *me)
{
	list *node, *next;

	for(node = me->next; node != NULL; node = next)
	{
		next = node->next;
		free(node);
	}

	free(me);
	return;
}
