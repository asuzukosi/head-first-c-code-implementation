/*
This is an application used to test the use of funcitons in c
*/

#include<stdio.h>


void complain(){
    puts("I'm sick of this");
}

int larger(int first, int second){
    if(first>second){
        return first;
    }
    return second;
}

int main(int argc, char const *argv[])
{
    int first = 100;
    int second = 1000;
    int x;
    int y;
    
    y =(x = 4);

    printf("The larger of the two numbers %i \n", larger(first, second));
    printf("The value of x is : %i and the value of y is %i \n", x, y);
    complain();
    return 0;
}
