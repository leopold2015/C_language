#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>

int main()
{
    key_t key = ftok(".", 1);

    int shmid = shmget(key, 1024, 0);

    char *str = (char *)shmat(shmid, NULL, 0);

    
    while(1)
    {
        printf("%s", str);
        if(strncmp(str, "end", 3) == 0)
        {
            break;
        }
        sleep(1);
    }

    shmdt(str);
    printf("Disconnect shared memory.\n");

    return 0;
}