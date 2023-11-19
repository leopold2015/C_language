#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    putchar('a');
    write(1, "b", 1);

    putchar('a');
    wtire(1, "b", 1);

    putchar('a');
    write(1, "b", 1);

    return 0;
}