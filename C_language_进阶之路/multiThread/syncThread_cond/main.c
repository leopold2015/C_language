#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex  = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

//buffer region
int buffer  = 0;
int data_avatilable = 0;

void* producer(void* arg)
{
    int i  = 0;
    for(i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&mutex);
        buffer = i; //shengchang shujv 
        data_avatilable = 1;
        printf("product: %d\n", buffer);
        
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex); 
        sleep(3);      
    }

    return NULL;
}

void* consumer(void* arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        while(!data_avatilable)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("Consumed: %d\n", buffer);
        data_avatilable = 0;
        pthread_mutex_unlock(&mutex);

    }

    return NULL;
}


int main()
{

    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid1, NULL, consumer, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
