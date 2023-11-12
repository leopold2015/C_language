#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFSIZE 1024

int main(int argc, char **argv)
{
    FILE *fps, *fpd;
    char buf[BUFFSIZE];
    int n = 0;

    if(argc < 3)
    {

        fprintf(stderr, "Usage:  %s <src_file > <dst_file>\n", argv[0]);
        exit(1);
    }

    fps = fopen(argv[1], "r");
    if(fps == NULL)
    {

        perror("fopen()");
        exit(1);
    }
    fpd = fopen(argv[2], "w");
    if(fpd == NULL)
    {
        fclose(fps);
        perror("fopen()");
        exit(1);
    }

    while((n =fread(buf, 1, BUFFSIZE, fps)) > 0 )
    {
        fwrite(buf, 1, n, fpd);
    }

    fclose(fpd);
    fclose(fps);

}

