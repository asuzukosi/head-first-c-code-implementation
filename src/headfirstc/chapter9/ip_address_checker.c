/*
This program is used to check for the ip address of a computer using network calls
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>


int main(int argc, char const *argv[])
{
    if(execl("/sbin/ifconfig", "/sbin/ifconfig", NULL) == -1){
        if(execlp("ipconfig", "ipconfig", NULL) == -1){
            fprintf(stderr, "cannot run ipconfig: %s\n", strerror(errno));
            return 1;
        }
    }
    return 0;
}
