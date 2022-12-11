#ifndef LLIST_H__
#define LLIST_H__

#define LLIST_FORWARD     1
#define LLIST_BACKWARD    2

typedef void llist_op(const void *);
typedef int llist_cmp(const void *, const void *);


struct llist_node_st
{
	//void *data;
	struct llist_node_st *prev;
	struct llist_node_st *next;	
	
	char data[1];  //占位符  c99中支持长度为0的数组，保险起见，可以把数组的长度写为1
};

typedef struct llist_head
{
	int size;
	struct llist_node_st head;
	int (*insert)(struct llist_head *, const void *, int);
	void *(*find)(struct llist_head *, const void *, llist_cmp *);
	int (*delete)(struct llist_head *, const void *, llist_cmp *);
	int (*fetch)(struct llist_head *, const void *, llist_cmp *, void *);
	void (*travle)(struct llist_head *, llist_op *);

}LLIST;


LLIST *llist_create(int initsize);

void llist_destroy(LLIST *);


#endif
