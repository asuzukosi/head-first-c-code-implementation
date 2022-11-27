/*
This application uses threads to contdown the nubmer of bottles of beer
*/

#include<stdio.h>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include"error.h"

long beers = 2000000;
pthread_mutex_t a_lock = PTHREAD_MUTEX_INITIALIZER;

void* count_bear(void *a){
    int i;
    for (i = 0; i < 100000; i++) {
        pthread_mutex_lock(&a_lock);
        beers = beers - 1;
        pthread_mutex_unlock(&a_lock);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    /* code */
    pthread_t threads[20];
    printf("%li bottles of beer on the wall\n%li bottles of beer\n", beers, beers);
    for (int i = 0; i < 20; i++)
    {
        if (pthread_create(&threads[i], NULL, count_bear, NULL) == -1){
            char msg[255];
            sprintf(msg, "Can't create thread t%i", i);
            error(msg);
        }
            
    }

    void* result;
    for (int i = 0; i < 20; i++){
        if (pthread_join(threads[i], &result) == -1){
            char msg[255];
            sprintf(msg, "Can't join thread t%i", i);
            error(msg);
        }
    }
    printf("There are now %li bottles of beer on the wall\n", beers);
    return 0;
}
