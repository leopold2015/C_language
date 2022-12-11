#include <stdio.h>

#include <stdlib.h>

int main()
{
	int *p = NULL;


	p = malloc(sizeof(int));
	if(p == NULL)
	{
		
		printf("p is NULL \n");
		exit(1);
	}

	*p = 10;
	printf(	"%p---->%d\n",*p);
	free(p);
	p = NULL;

	*p = 123;
	printf("%p ---->%d\n", *p);


	exit(0);

		

}
