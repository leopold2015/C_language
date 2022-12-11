#ifndef LLIST_H__
#define LLIST_H__

#define LLIST_FORWARD     1
#define LLIST_BACKWARD    2

typedef void llist_op(const void *);
typedef int llist_cmp(const void *, const void *);


struct llist_node_st
{
	void *data;
	struct llist_node_st *prev;
	struct llist_node_st *next;	
	
	//char data[0];  //占位符  c99中支持长度为0的数组，保险起见，可以把数组的长度写为1
};

typedef struct
{
	int size;
	struct llist_node_st head;
}LLIST;


LLIST *llist_create(int initsize);

int llist_insert(LLIST *, const void *data, int mode);

void * llist_find(LLIST *, const void *, llist_cmp *);

int llist_delete(LLIST *, const void *key, llist_cmp *);

int llist_fetch(LLIST *, const void *key, llist_cmp *,void *data);


void llist_travle(LLIST*, llist_op *);


void llist_destroy(LLIST *);


#endif
