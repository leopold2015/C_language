/*************************************************************************
	> File Name: fibonacci.c
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 日  1/17 23:29:53 2021
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

static void fibonacci(void)
{
	int i, j, tmp;
	int fib[10] = {1,1};

	for(i = 2; i < 10; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}
	for(i = 0; i < 10; i++)
	{
		printf("%d ", fib[i]);
	}
	printf("\n");

	i = 0;
	j = sizeof(fib)/sizeof(fib[0])-1;

	while(i < j)
	{
		tmp = fib[i];
		fib[i] = fib[j];
		fib[j] = tmp;

		i++;
		j--;
	}

	for(int k = 0; k < 10; k++)
	{
		printf("%d ",fib[i]);
	}
	printf("\n");
	return ;

}


int main()
{

	fibonacci();
	exit(0);
}
