#include <stdio.h>

int f(int args1, int args2, int args3, int args4, int args5, int args6)
{
    int s = 0;
    s = args1+ args2 + args3 + args4+ args5 + args6;
    return s;


}

int main(void)
{

    int sum = 0;
    sum = f(1,2,3,4,5,6);
    printf("sum: %d\n", sum);

    return 0;
}