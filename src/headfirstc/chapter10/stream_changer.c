/*
This is a program that takes in a list of rss files and scans them
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

int main(int argc, char const *argv[])
{
    char *feed[] = {
        "https://www.feedforall.com/sample.xml",
        "https://www.feedforall.com/sample-feed.xml",
        "https://www.feedforall.com/blog-feed.xml",
        "http://www.rss-specifications.com/blog-feed.xml"
    };

    int size = sizeof(feed)/sizeof(char*);
    FILE *outputfile = fopen("stories.txt", "w");
    int outputfile_no = fileno(outputfile);

    for (int i = 0; i < size; i++)
    {   

        pid_t pid = fork();
 

        if(pid == -1 ){
            error("failed to start child process");
        }

        if(!outputfile){
            error("failed to open output file");
        }
        if(dup2(outputfile_no, 1)== -1){
            error("failed to duplicate output stream to stories.txt");
        }

        int fd[2];

        if(pipe(fd) == -1){
            error("can't create the pipe");
        }

        if(!pid){
            char var[255];
            sprintf(var, "RSS_FEED=%s", feed[i]);
            char *vars[] = {var, NULL};
            
            dup2(fd[1], 1);
            close(fd[0]);
        
            if(execle("/usr/bin/python", "/usr/bin/python", "rssgossip.py", "sample",NULL, vars) == -1){
                error("cannot run rssgossip.py");
            }

            return 1;
        }

        dup2(fd[0], 0);
        close(fd[1]);

        char line[255];
        while(fgets(line, 255, stdin)){
            if(line[0] != '\t'){
                open_url(line+1);
            }
        }
        int pid_status; 

        if(waitpid(pid, &pid_status, 0) == -1){
            error("unable to wait for child process");
        }

    
    }
        
    return 0;
}
