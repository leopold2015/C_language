#include <stdio.h>
#include <errno.h>

int main()
{
    FILE *fp = NULL;
    fp = fopen("tmp", "w");

    if(fp == NULL)
    {
        fprintf(stderr, "fopen failed !! errno = %d\n", errno);
        perror("fopen()");
        fprintf(stderr, "fopen():%s\n", strerror(errno));

        exit(1);

    }

    puts("OK!!");

    fclose(fp);
    exit(0);

}