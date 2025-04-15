#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
unsigned int i = 0;


void* do_work(void* arg)
{
    pthread_mutex_lock(&lock);
    //fangwen huozhe xiugai gongxiangziyuan
    
    printf("Thread is working with mutual exclusion.\n");
    //while(1)
    //{
        printf("Thread %d is working with mutual exclusion i %d.\n", *(int*) arg, i);
        i++;

    //}

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main()
{
    pthread_t tid1, tid2;
    int arg1 = 1, arg2 = 2;

    pthread_create(&tid1, NULL, do_work, &arg1);
    pthread_create(&tid2, NULL, do_work, &arg2);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_mutex_destroy(&lock);

    return 0;

}