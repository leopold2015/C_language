#include <stdio.h>
#include <stdlib.h>


#if 0
n = n-1 + n-2
#endif


int fib(int n)
{
	if(n < 1)
		return -1;

	if(n == 1 || n == 2)
		return 1;

	return fib(n- 1) + fib(n-2);
}

int main()
{

	int n;
	int res;

	scanf("%d", &n);

	res = fib(n);

	printf("fib[%d]= %d\n", n, res);

	return 0;
}
