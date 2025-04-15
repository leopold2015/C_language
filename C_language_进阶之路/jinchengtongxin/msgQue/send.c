#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

struct msgstru
{
    long msgtype;
    char msgtext[1024];
};

void main()
{
    struct msgstru msgs;
    int msg_type;
    char str[256];
    int ret_value;
    int msgid;
    key_t key;

    key = ftok(".", 13);
    printf("key = %x\n", key);

    msgid = msgget(key, IPC_EXCL);
    if(msgid < 0)
    {
        msgid = msgget(key, IPC_CREAT | 0777);

        if(msgid < 0)
        {
            printf("failed to create msq | errno = %d [%s]\n", errno, strerror(errno));
            exit(-1);
        }
    }

    while(1)
    {
        printf("Input message type(end:0):");
        scanf("%d", &msg_type);
        if(msg_type == 0)
        {
            break;
        }

        printf("Input message to be sent:");
        scanf("%s", str);
        msgs.msgtype = msg_type;
        strcpy(msgs.msgtext, str);

        ret_value = msgsnd(msgid, &msgs, sizeof(struct msgstru), IPC_NOWAIT);
        if(ret_value < 0)
        {
            printf("msgsnd() write msg failed, errno = %d [%s]\n", errno, strerror(errno));
            exit(-1);

        }
    }

    msgctl(msgid, IPC_RMID, 0);

}