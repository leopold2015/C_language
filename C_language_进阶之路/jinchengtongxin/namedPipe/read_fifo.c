#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    int fd = 0;
    int len = 0;
    pid_t pid;
    char buf[1024] = {0};
    printf("The \"read_fifo\" process ID is %d \n", getpid());

    if(mkfifo("./fifo", 0666) < 0 && errno != EEXIST)
    {
        perror("Create FIFO Failed\n");
    }

    system("chmod 777 -R ./*");

    if((fd = open("./fifo", O_RDONLY | O_NONBLOCK)) < 0)
    {
        perror("Open FIFO Failed \n");
        exit(1);
    }

    while(1)
    {
        if(len = read(fd, buf, 1024) > 0)
        {
            printf("The file size is %d bytes.\n", len);
            printf("Read message:%s\n", buf);

        }
        else
        {
            break;
        }
    }

    close(fd);

    return 0;
}