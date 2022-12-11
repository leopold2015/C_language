#ifndef NOHEAD_H__
#define NOHEAD_H__

#define NAMESIZE   32


typedef struct score_st
{

	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
}stu_score;

struct node_st
{
	stu_score data;
	struct node_st *next;
};


int list_insert(struct node_st **, stu_score *data);
int list_show(struct node_st *);

int list_delete(struct node_st **);
stu_score * list_find(struct node_st *, int id);

void list_destroy(struct node_st *list);


#endif
