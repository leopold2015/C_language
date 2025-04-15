#include <pthread.h>
#include <stdio.h>

// work function
void* do_work(void *args)
{

    printf("Thread is working \n");
    while(1)
    {
        printf("I am working\n");
        sleep(1);
    }

}

int main()
{
    pthread_t tid;

    pthread_create(&tid, NULL, do_work, NULL);

    pthread_join(tid, NULL);

    return 0;
}