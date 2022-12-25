#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

struct score_st
{
	int id;
	char name[32];
	int math;
	int chinese;
};

void print_s(void *record)
{
	struct score_st *r = record;

	printf("%d %s %d %d\n", r->id, r->name, r->math, r->chinese);
}

int main()
{

	STACK *st ;
	struct score_st tmp;
	int i, ret;

	st = stack_create(sizeof(struct score_st));
	if(st == NULL)
		exit(1);

	for(i = 0; i < 7; i++)
	{
		tmp.id = i;
		snprintf(tmp.name, 32, "stu%d", i);
		tmp.math = rand()%100;
		tmp.chinese = rand()%100;

		if(stack_push(st, &tmp))
			exit(1);
	}
	
	while(1)
	{
		ret = stack_pop(st, &tmp);
		if(ret == -1)
			break;
		print_s(&tmp);
	}
	


	stack_destroy(st);


	exit(0);
}
