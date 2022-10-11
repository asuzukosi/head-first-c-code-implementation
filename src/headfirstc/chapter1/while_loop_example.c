/*
This is an example on how to create loops in c
*/

#include<stdio.h>


int main(int argc, char const *argv[])
{
    int counter = 0;

    while(counter <  7){
        puts("I'm still in the loop");
        counter ++;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("We are on iteration %i \n", i);
    }
    

    return 0;
}
