#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char ** argv)
{
    struct passwd *pwdline;
    printf("argc = %d\n", argc);
    if (argc < 2)
    {
        fprintf(stderr, "usages..");
        exit(1);
    }
    
    for(int i = 0;i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    pwdline = getpwuid(atoi(argv[1]));
    puts(pwdline->pw_name);

    exit(0);
}