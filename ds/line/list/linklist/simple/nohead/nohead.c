#include <stdio.h>
#include <stdlib.h>

#include "nohead.h"

int list_insert(struct node_st **list, stu_score *data)
{
	//只实现首部输入
	struct node_st * new;

	new = malloc(sizeof(*new));
	if(new == NULL)
	{
		return -1;
	}

	new->data = *data;
	//new->next = NULL;

	new->next = NULL;
	*list = new;

	return 0;
}
int list_show(struct node_st * list)
{

	struct node_st *cur;

	for(cur = list; cur != NULL; cur = cur->next)
	{
		printf("%d %s %d %d\n", cur->data.id, cur->data.name, cur->data.math, cur->data.chinese);
	}
	return 0;
}
int list_delete(struct node_st **list)
{
	struct node_st *cur;

	if(*list == NULL)
		return -1;
	cur = *list;
	*list = (*list)->next;
	free(cur);
	return 0;
}
stu_score * list_find(struct node_st *list, int id)
{
	struct node_st *cur;

	for(cur = list; cur != NULL; cur = cur->next)
	{
		if(cur->data.id ==id)
		{
			//printf("%d %s %d %d\n", cur->data.id, cur->data.name, cur->data.math, cur->data.chinese);
			return &cur->data;
		}
		
	}
	//printf("Can not find\n");
	return NULL;
}

void list_destroy(struct node_st *list)
{
	struct node_st *cur;

	if(list == NULL)
		return ;

	for(cur = list; cur != NULL; cur = list)
	{
	
		list = list->next;
		free(cur);
	}
}

