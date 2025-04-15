#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

struct msgstru
{
    long msgtype;
    char msgtext[1024];
};

void main()
{
    struct msgstru msgs;
    char str[256];
    int retValue;
    int msgid;
    int i = 0;
    key_t key;

    key = ftok(".", 13);
    printf("key = %x\n", key);

    while(1)
    {
        msgid = msgget(key, IPC_EXCL);

        if(msgid < 0)
        {
            printf("msq not exited !! errno=%d [%s]\n", errno, strerror(errno));
            i++;
            sleep(1);
        }
        else
        {
            i = 0;
        }

        if(i == 3)
        {
            break;
        }

        retValue = msgrcv(msgid, &msgs, sizeof(struct msgstru), 0, 0);
        printf("type = [%ld], text = [%s]\n", msgs.msgtype, msgs.msgtext);
    }

    return;
}