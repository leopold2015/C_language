#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <glob.h>
#include <string.h>

static int path_noloop(const char *path)
{
    char *pos;
    pos = strrchr(path, '/');
    if(pos == NULL)
    {
        exit(1);
    }
    if(strcmp(pos + 1, ".") == 0 || strcmp(pos + 1, "..") == 0)
    {
        return 0;
    }

    return 1;
}

static int64_t mydu(const char *path)
{
    struct stat statres;
    char nextpath[1024];
    glob_t globres;
    int i = 0, sum = 0;
    if(lstat(path, &statres))
    {
        perror("lstat()");
        exit(1);
    }

    if(!S_ISDIR(statres.st_mode))
    {
        return statres.st_blocks;
    }
    strncpy(nextpath, path, 1024);
    strncat(nextpath, "/*", 1024);

    glob(nextpath, 0, NULL, &globres);

    strncpy(nextpath, path, 1024);
    strncat(nextpath, "/*", 1024);
    
    glob(nextpath, GLOB_APPEND, NULL, &globres);

    for(i = 0; i < globres.gl_pathc; i++)
    {
        if(path_noloop(globres.gl_pathv[i]))
            sum += mydu(globres.gl_pathv[i]);
    }
    sum += statres.st_blocks;
    globfree(&globres);
    return sum;
}


int main(int argc, char ** argv)
{
    printf("argc = %d\n", argc);
    if(argc < 2)
    {
        fprintf(stderr, "usage ..\n");
        exit(1);
    }
    for(int i = 0;i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    printf("%lld\n", mydu(argv[1]));

    exit(0);
}