#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main()
{
    int fd[2];
    pid_t pid;
    char buff[20] = {0};

    // create pipe
    if(pipe(fd) < 0)
    {
        printf("create pipe error\n");
    }

    if((pid = fork()) < 0)
    {
        printf("fork error\n");
    }
    else if(pid > 0)
    {
        sleep(3);

        printf("The parent process id is %d .\n", getpid());
        
        // close read end
        /*
        close(fd[0]);
        write(fd[1], "hello world!\n", strlen("hello world!\n"));
        */

        // close write end
        close(fd[1]);
        // if pipe is empty, the process will block
        read(fd[0], buff, 20);
        printf("%s \n", buff);

    }
    else
    {
        printf("The child process id is %d.\n", getpid());

        // close write end
        /*
        close(fd[1]);
        // if pipe is empty, the process will block
        read(fd[0], buff, 20);
        printf("%s\n", buff);
        */

        close(fd[0]);
        write(fd[1], "hello world!\n", strlen("hello world!\n"));



        exit(0);
    }


    return 0;
}