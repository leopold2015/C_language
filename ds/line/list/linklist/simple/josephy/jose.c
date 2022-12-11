#include <stdio.h>
#include <stdlib.h>


#define JOSENUMBER   8
struct node_st
{
	int data;
	struct node_st *next;
};

struct node_st * jose_create(int n)
{
	struct node_st *me;
	struct node_st *new, *cur;
	int i = 1;

	me = malloc(sizeof(*me));
	if(me == NULL)
	{
		return NULL;
	}
	me->data = i;
	me->next = me;
	i ++;

	cur = me;
	for(; i <= n; i++)
	{
		new = malloc(sizeof(*new));
		if(new == NULL)
			return NULL;

		new->data = i;
		new->next = cur->next;
		cur->next = new;
		cur = new;
	}

	return me;
	
}

void jose_show(struct node_st *me)
{
	struct node_st *list;
	for(list = me;list->next != me;list = list->next)
	{
		printf("%d ", list->data);
	}

	printf("%d \n", list->data);
}

void jose_kill(struct node_st ** me, int n)
{
	int i = 1;
	struct node_st *cur, *node;
	cur = *me;
	while(cur != cur->next)
	{
		while(i < n)
		{
			node = cur;
			cur = cur->next;

			i++;
		}
		printf("%d ", cur->data);
		node->next = cur->next;
		free(cur);

		cur = node->next;
		i = 1;
	}	
	*me = cur;

	printf("\n");
}


int main()

{
	int n = 3;
	struct node_st *list;
	list = jose_create(JOSENUMBER);

	jose_show(list);

	jose_kill(&list, n);

	jose_show(list);


	exit(0);
}
