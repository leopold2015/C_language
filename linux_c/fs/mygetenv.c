#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    puts(getenv("PATH"));
    //测试pmap，使程序停在这儿
    getchar();

    exit(0);
}