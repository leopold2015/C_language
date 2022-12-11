#include <stdio.h>
#include <stdlib.h>


#if 0
void func(int **p, int n)
{
	*p = malloc(n);
	if(*p == NULL)
		exit(1);
	return;
}

#else

void *func(int *p, int n)
{

	p = malloc(n);
	if(p == NULL)
		exit(1);
	return p;
}

#endif


int main()
{


	int num  = 100;
	int *p = NULL;

	//func(&p, num);
	
	p = func(p, num);

	free(p);

	exit(0);
}
