
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>


void error(char* message){
    fprintf(stderr, "%s : %s \n",message, strerror(errno));
    exit(1);
}