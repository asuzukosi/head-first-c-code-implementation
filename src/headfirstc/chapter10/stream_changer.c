/*
This is a program that takes in a list of rss files and scans them
*/

#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>


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
        if(!pid){
            char var[255];
            sprintf(var, "RSS_FEED=%s", feed[i]);
            char *vars[] = {var, NULL};

            if(execle("/usr/bin/python", "/usr/bin/python", "rssgossip.py", "sample",NULL, vars) == -1){
                error("cannot run rssgossip.py");
            }

            return 1;
        }
    
    }
        
    return 0;
}
