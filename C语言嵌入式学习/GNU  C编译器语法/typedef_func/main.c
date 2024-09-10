#include <stdio.h>

typedef int (*func_t)(int a, int b);

int sum(int a, int b)
{

    return a + b;
}

int main(void)
{
    func_t func = sum;
    printf("%d\n", func(1, 2));


    return 0;
}