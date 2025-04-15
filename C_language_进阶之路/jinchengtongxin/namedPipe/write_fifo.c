#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    int i = 0;
    char *buf = "Nothing's gonna change my love for you.\n";
    printf("The \"write_fifo\" process ID is %d\n", getpid());

    if(fd == open("./fifo", O_WRONLY | O_NONBLOCK) < 0)
    {
        perror("Open FIFO failed\n");
        exit(1);
    }

    for(i = 0; i < 5; i++)
    {
        printf("send message: %s \n", buf);
        if(write(fd, buf, strlen(buf) + 1) < 0)
        {
            perror("write FIFO failed\n");
            close(fd);
            exit(1);
        }
        sleep(1);
    }

    close(fd);
    return 0;
}