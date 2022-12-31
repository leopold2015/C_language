#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#define NAMESIZE  32


struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;

};

print_st(void *record)
{
	struct score_st *r = record;

	printf("%d %s %d %d\n", r->id, r->name, r->math, r->chinese);
}

int main()
{
	int i, ret;
	QUEUE *qu;
	struct score_st tmp;
	qu = queue_create(sizeof(struct score_st));
		
	if(qu == NULL)
		exit(1);


	for(i = 0; i < 6; i++)
	{
		tmp.id = i;
		snprintf(tmp.name, NAMESIZE, "stu%d", i);
		tmp.math = rand()%100;
		tmp.chinese = rand()%100;

		if(queue_en(qu, &tmp) != 0)
			break;

	}

	while(1)
	{
		ret = queue_de(qu, &tmp);
		if(ret != 0)
		{
			break;
		}
		print_st(&tmp);
	}

	queue_en(qu, &tmp);

	exit(0);
}
