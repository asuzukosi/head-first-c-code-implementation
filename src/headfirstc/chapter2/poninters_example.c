/*
Testing out the use of pointers in c
*/
#include<stdio.h>

int my_global = 0;


int main(int argc, char const *argv[])
{
    int x = 4;

    printf("The memory address of variable x is %p \n", &x);
    printf("The memorty addresss of global variable my_global is %p \n", &my_global);
    return 0;
}
