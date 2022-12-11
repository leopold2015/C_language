#include <stdio.h>
#include <stdlib.h>

int print_value(int a, int b)
{
	printf("%d %d\n", a, b);
	return 0;
}

int swap_value(int* a, int* b)

{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int i = 3, j = 5;
	print_value(i,j);

	// 地址传递
	swap_value(&i,&j);

	printf("i = %d j = %d\n", i,j);

	return 0;
}
