/*
This is a program meant to demo interupt handling with c
*/
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

/*
This is the handler function that kicks in when the process
is ended
*/
void diedie(int sig){
    puts("\nGoodbye cruel world ... \n");
    exit(1);
}

int catch_signal(int sig, void (*handler)(int)){
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);

    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}

int main(int argc, char const *argv[])
{
    if(catch_signal(SIGINT, diedie) == -1){
        fprintf(stderr, "Can't map the handler");
        exit(2);
    }
    char name[30];
    printf("Enter your name: ");
    fgets(name, 30, stdin);
    printf("Hello %s\n", name);
    return 0;
    return 0;
}
