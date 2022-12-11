#include <stdio.h>
#include <stdlib.h>

typedef int INT;

#define INT int


int main()
{
/*
 	#define IINT int
	typedef int INT;

	INT i;    ----->   int i;


#define IP int *
typedef int *IP;


IP p, q;    ---->   int *p,q;
IP p, q;    ------>   int *p, *q;




typedef int ARR[6];     ------>   int [6] -> ARR;

ARR a;   ------>   int a[6];



struct node_st
{
	int i;
	float f;
};

typedef struct node_st NODE;
NODE a;  -->   struct node_st a;

typedef struct node_st *NODEP;

NODEP p;  ---> sttuct node_st *p;


typedef struct
{
	int i;
	float f;
}NODE, *NODEP;


typedef int FUNC(int);  ->   int(int)   FUNC;函数名叫FUNC；
FUNC f;   ->  int f(int);

typedef int *FUNCP(int);

FUNCP p;  --->   int *p(int);  //指针函数


typedef int *(*FUNCP)(int);
FUNCP p;  --> int *(*p)(int);   //指向函数的指针，该指针指向指针函数  




 * /












       	i = 100;
	printf("%d\n", i);
	exit(0);
}
