/*
This is a program that takes in a list of rss files and scans them
*/

#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<errno.h>

int main(int argc, char const *argv[])
{
    char *feed[] = {
        "https://www.feedforall.com/sample.xml",
        "https://www.feedforall.com/sample-feed.xml",
        "https://www.feedforall.com/blog-feed.xml",
        "http://www.rss-specifications.com/blog-feed.xml"
    };

    int size = sizeof(feed)/sizeof(char*);
    for (int i = 0; i < size; i++)
    {   

        pid_t pid = fork();
        if(pid == -1 ){
            fprintf(stderr, "failed to start child process");
            return 1;
        }

        if(!pid){
            char var[255];
            sprintf(var, "RSS_FEED=%s", feed[i]);
            char *vars[] = {var, NULL};

            if(execle("/usr/bin/python", "/usr/bin/python", "rssgossip.py", "sample",NULL, vars) == -1){
                fprintf(stderr, "cannot run rssgossip.py %s\n", strerror(errno));
            }

            return 1;
        }
    
    }
        
    return 0;
}
