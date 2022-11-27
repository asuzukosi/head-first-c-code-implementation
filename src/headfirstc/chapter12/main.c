/*
Building multi threaded applications in c
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<pthread.h>
#include"error.h"


void* does_too(){
    for (size_t i = 0; i < 4; i++){
        sleep(1);
        puts("Does too !");
    }
    return NULL;
}

void* does_not(){
    for (size_t i = 0; i < 4; i++){
        sleep(1);
        puts("Does not !");
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    /* code */

    pthread_t t0;
    pthread_t t1;

    if (pthread_create(&t0, NULL, does_not, NULL) == -1)
        error("Can't create thread t0");

    if (pthread_create(&t1, NULL, does_too, NULL) == -1)
        error("Can't create thread t1");


    void* result;
    if (pthread_join(t0, &result) == -1)
        error("Can't join thread t0");

    if (pthread_join(t1, &result) == -1)
        error("Can't join thread t1");

    return 0;
}
