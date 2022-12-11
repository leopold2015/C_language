#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include <string.h>
#define NAMESIZE    32

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};

static void print_s(const void *record)
{
	const struct score_st *r = record;
	printf("%d %s %d %d\n", r->id, r->name, r->math, r->chinese);
}

static int id_cmp(const void *key, const void *record)
{
	const int *k = key;
	const struct score_st *r = record;

	return (*k - r->id);

}

static int name_cmp(const void *key, const void *record)
{
	const char *k = key;
	const struct score_st *r = record;

	return strcmp(k, r->name);
}

int main()
{

	int i = 0;
	int ret = 0;

	LLIST *handler;
	struct score_st tmp;

	handler = llist_create(sizeof(struct score_st));
	if(handler == NULL)
	{
		exit(1);
	}

	for(i = 0; i < 7; i++)
	{
		tmp.id = i;
		snprintf(tmp.name, NAMESIZE, "std%d", i);
		tmp.math = rand()%100;
		tmp.chinese = rand()%100;
	

	//handler = llist_create(7);
	
		ret = llist_insert(handler, &tmp, LLIST_FORWARD);
		if(ret)
			exit(1);
	}
	llist_travle(handler,print_s);
#if 1 

	printf("\n\n");

	int id = 30;

	struct score_st *data;
	data = llist_find(handler, &id, id_cmp);
	if(data == NULL)
		printf("Can't find the key!!!\n");
	else
		print_s(data);

	printf("\n\n");

	int id_del = 3;
	printf("mgh ===== llist_delete star delete id :%d\n", id_del);
	ret = llist_delete(handler, &id_del, id_cmp);
	printf("mgh ===== llist_delete finish\n");
	if(ret)
	{
		printf("llist_delete failed!!!\n");
	}

	llist_travle(handler, print_s);

	char *del_name = "std6";
	printf("mgh ===== llist_delete star delete name :%s\n", del_name);
	ret = llist_delete(handler, del_name, name_cmp);
	if(ret)
		printf("llist_delete failed!!!\n");
	
	llist_travle(handler, print_s);
#endif
	exit(0);
}
