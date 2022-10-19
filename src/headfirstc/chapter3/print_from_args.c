/*
Write c program to read from arguements passed into the program
*/

#include<stdio.h>
#include<unistd.h>


int main(int argc, char *argv[])
{   
    char ch;
    char *change = "";
    char *hate = "";

    while ((ch = getopt(argc, argv, "c:d:")) != EOF){
        switch (ch){
        case 'c':
            change = optarg;
            break;
        case 'd':
            hate = optarg;
            break;
        default:
            break;
        }
    }
    printf("%s is change \n", change);
    printf("%s is hate \n", hate);
    return 0;
}
