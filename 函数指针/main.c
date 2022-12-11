#include <stdio.h>
#include <stdlib.h>

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}


int main()
{
	int a = 3, b = 5;
	int ret;
	int i;

	int (*p)(int, int);
	int (*q)(int, int);
		
	int (*funcp[2])(int, int);
	
	p = add;
	q = sub;
	//ret = add(a,b);
	//
	ret = p(a,b);
	printf("%d\n", ret);


	ret = q(a, b);
	printf("%d \n", ret);



	funcp[0] = add;
	funcp[1] = sub;

	for(i = 0; i < 2; i++)
	{
		ret = funcp[i](a, b);

		printf("%d \n", ret);
	}
	exit(0);	

}
