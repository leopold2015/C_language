#include <stdio.h>
#include <stdlib.h>
#include <glob.h>

#define   PAT   "/etc/a*.conf"
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

    glob_t globres;
    int err = 0;
    err = glob(PAT, 0, NULL, &globres);
    if(err)
    {
        printf("Error code = %d\n", err);
        exit(1);
    }
    for(int i = 0; i < globres.gl_pathc; i++)
    {
        puts(globres.gl_pathv[i]);
    }

    exit(0);
}