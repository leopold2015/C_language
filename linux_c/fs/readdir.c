#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#define   PAT   "./"
#if 0
int errfunc_(const char *errpath, int errno)
{
    puts(errpath);
    fpprintf(stderr, "ERRoR  msg %s \n", stderror(errno));
    return 0;
}
#endif

int main(int argc, char ** argv)
{
    printf("argc = %d\n", argc);
    for(int i = 0;i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }


    DIR *dp;
    struct dirent *cur;
    dp = opendir(PAT);
    if(!dp)
    {
        perror("opendir()");
        exit(1);
    }
    while((cur = readdir(dp)) != NULL)
    {
        puts(cur->d_name);
    }

    closedir(dp);
    
    exit(0);
}