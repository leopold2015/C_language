#include <stdio.h>
int buffer[0];

struct bufStr
{

    int len;
    int a[0];

};

int main(void) {
    printf("%lu\n", sizeof(buffer));
    printf("%lu\n", sizeof(struct bufStr));

    struct bufStr *buf;
    buf = (struct bufStr *)malloc(sizeof(struct bufStr) + 20);
    buf->len = 20;
    strcpy(buf->a, "Hello world, I am coming\n");
    puts(buf->a);
    
    free(buf);

    return 0;
}