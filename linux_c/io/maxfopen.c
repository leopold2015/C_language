#include <stdio.h>
#include <errno.h>

int main()
{
    FILE *fp = NULL;
    int count = 0;
    
    while(1)
    {
        fp = fopen("tmp", "w");

        if(fp == NULL)
        {
            //fprintf(stderr, "fopen failed !! errno = %d\n", errno);
            perror("fopen()");
            //fprintf(stderr, "fopen():%s\n", strerror(errno));

            break;

        }
        count++;

    }

    printf("count = %d\n", count);
    

    //puts("OK!!");

    fclose(fp);
    exit(0);

}