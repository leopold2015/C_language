#include <stdio.h>

#include <stdlib.h>


struct node_st
{
	int coef;   //coeficient
	int exp;    //exponent

	struct node_st *next;
};

struct node_st* poly_create(int a[][2], int n)
{
	struct node_st *me;
	struct node_st *newnode, *cur;
	int i = 0;

	me = malloc(sizeof(*me));
	if(me == NULL)
		return NULL;

	me->next = NULL;
	cur = me;

	for(i = 0;i < n;i++)
	{
		newnode = malloc(sizeof(*newnode));
		if(newnode == NULL)
			return NULL;

		newnode->coef = a[i][0];
		newnode->exp = a[i][1];
		newnode->next = NULL;

		cur->next = newnode;
		cur = newnode;
	}
	
	return me;
}

void poly_show(struct node_st *me)
{
	struct node_st *cur;

	for(cur = me->next; cur != NULL; cur = cur->next)
	{
		printf("(%d %d)", cur->coef, cur->exp);
	
		
	}

	printf("\n");
	
}

void poly_union(struct node_st *p1, struct node_st *p2)
{
	struct node_st *p, *q, *r;

	p = p1->next;
	q = p2->next;
	r = p1;

	while(p && q)
	{
		if(p->exp < q->exp)
		{
			r->next = p;
			r = p;
			p = p->next;
		}
		else if(p->exp > q->exp)
		{
			r->next = q;
			r = q;
			q = q->next;
		}
		else //p->exp == q->exp
		{
			p->coef += q->coef;
			if(p->coef)
			{
				r->next = p;
				r = p;
				//p = p->next;
				//q = q->next;
			}
			
			p = p->next;
			q = q->next;
		}
	}


	if(p == NULL)
		r->next = q;
	else
		r->next = p;
}

int main()
{
	int a[][2] = {{5,0},{2,1},{8,8},{3, 16}};
	int b[][2] = {{6,1 }, {16, 6}, {-8, 8}};

	struct node_st *p1, *p2;

	p1 = poly_create(a, 4);
	if(p1 == NULL)
		exit(1);
	
	p2 = poly_create(b, 3);
	if(p1 == NULL)
                exit(1);

	poly_show(p1);
	poly_show(p2);

	poly_union(p1,p2);
	poly_show(p1);
	
	
	exit(0);

}

