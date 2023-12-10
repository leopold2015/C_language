#include <stdio.h>
#include <stdlib.h>

static void f1(void)
{
    printf("f1 is working\n");
}

static void f2(void)
{
    printf("f2 is working\n");
}
static void f3(void)
{
    printf("f3 is working\n");
}

int main(int argc, char ** argv)
{
    puts("begin\n");

    atexit(f1);
    atexit(f2);
    atexit(f3);

    puts("end\n");    
    exit(0);
}