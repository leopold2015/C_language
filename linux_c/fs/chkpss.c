#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <shadow.h>
#include <unistd.h>

int main(int argc, char ** argv)
{
    char *crypted_pass;
    char *inputpass;
    struct spwd *shadowline;
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

    inputpass = getpass("PassWord:");
    shadowline = getspnam(argv[1]);
    crypted_pass = crypt(inputpass, shadowline->sp_pwdp);

    if(strcmp(shadowline->sp_pwdp, crypted_pass) == 0)
    {
        puts("OK!");
    }
    else
    {
        puts("failed!");
    }

    exit(0);
}