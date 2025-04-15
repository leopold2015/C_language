#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <string.h>

int main()
{
    key_t key;

    int shmid = 0;
    char *str = NULL;

    key = ftok(".", 1);

    shmid = shmget(key, 1024, IPC_CREAT|0666);
    if(shmid < 0)
    {
        printf("Failed to create shared memory.\n");
        exit(-1);
    }

    str = (char*)shmat(shmid, NULL, 0);
    if(str == (char*) -1)
    {
        printf("Failed to create shared memory\n");
        exit(-1);
    }
    else
    {
        printf("Shared memory created successfully.\n");
    }

    while(1)
    {
        printf("please enter:");
        fgets(str, 127, stdin);

        if(strncmp(str, "end", 3) == 0)
        {
            break;
        }
    }

    shmdt(str);
    printf("Disconnect shared memory.\n");
    shmctl(shmid, IPC_RMID, NULL);
    printf("Delete shared memory\n");

    return 0;

}