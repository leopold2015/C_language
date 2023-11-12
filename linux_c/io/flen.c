#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv)
{

    FILE *fp = NULL;
    int count = 0;
    if(argc < 2)
    {
        fprintf(stderr, "Usage ...\n");
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        perror("fopen()");
        exit(1);
    }
    while(fgetc(fp) != EOF)
    {
        count ++;
    }

    printf("count = %d\n", count);

    fclose(fp);

    exit(0);

}