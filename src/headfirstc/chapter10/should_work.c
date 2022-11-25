/*
This is the implementation of newshound that should work
*/
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/wait.h>
#include"url_opener.h"

void error(char* message){
    fprintf(stderr, "%s : %s \n",message, strerror(errno));
    exit(1);
}

int main(int argc, char *argv[])
{
    char *phrase = argv[1];
    char *vars[] = {"RSS_FEED=https://www.feedforall.com/sample.xml", NULL};
    int fd[2];

    if (pipe(fd) == -1) {
        error("Can't create the pipe");
    }

    pid_t pid = fork();

    if (pid == -1) {
        error("Can't fork process");
    }

    if(!pid){
        dup2(fd[1], 1);
        close(fd[0]);

        if(execle("/usr/bin/python", "/usr/bin/python", "rssgossip.py", phrase, NULL, vars) == -1){
            error("cannot run rssgossip.py");
        }
    }

    dup2(fd[0], 0);
    close(fd[1]);

    char line[255];
    while(fgets(line, 255, stdin)){
        if(line[0] != '\t'){
                open_url(line+1);
        }
    }
    return 0;
}
