#include <stdio.h>
#include "module.h"

void func1(void)
{

    printf("func1...\n");
}

void func2(void)
{

    printf("func2...\n");
}

int main(void)
{
    runcallback(func1);
    runcallback(func2);

    return 0;
}