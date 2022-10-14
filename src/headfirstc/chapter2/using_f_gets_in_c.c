/*
Using fgets instead of scanf in c
*/

#include<stdio.h>

int main(int argc, char const *argv[])
{
    char fullname[20];
    puts("Enter your full name \n");
    fgets(fullname, 20, stdin);


    printf("The full name is %s \n", fullname);
    return 0;
}
