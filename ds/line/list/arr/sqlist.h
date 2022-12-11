#ifndef SQLIST_H__
#define SQLIST_H__


#define DATASIZE     1024

typedef int datatype;

typedef struct node_st
{

	datatype data[DATASIZE];
	int last;
}sqlist;

sqlist *sqlist_create();

void sqlist_create1(sqlist **me);

int sqlist_insert(sqlist *, int i, datatype *);

int sqlist_delete(sqlist *, int i);

int sqlist_find(sqlist *, datatype *);

int sqlist_isempty(sqlist *);
 
int sqlist_setempty(sqlist *);

int sqlist_getnum(sqlist *);

int sqlist_display(sqlist *);

int sqlist_destroy(sqlist *);


int sqlist_union(sqlist *, sqlist *);


#endif
