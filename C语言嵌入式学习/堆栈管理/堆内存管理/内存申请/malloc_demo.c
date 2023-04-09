#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{

    char *p = NULL;

    p = (char*)malloc(100);
    printf("%p\n", p);

    memset(p, 0, 100);

    memcpy(p, "hello", 5);

    printf("%s\n", p);

    p = (char *)realloc(p, 200);
    printf("%p\n", p);
    printf("%s\n", p);

    free(p);
    return 0;
}