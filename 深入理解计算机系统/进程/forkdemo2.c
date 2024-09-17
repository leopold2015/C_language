#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid;
    int x = 1;
    if (fork() == 0)
    {
        // 子进程
        printf("This is child process x = %d\n",++x); // 子进程的pid为0
        //exit(0);
    }

    // 父进程
    printf("This is parent process x = %d\n",--x); // 父进程的pid为子进程的pid+1
    exit(0);
}