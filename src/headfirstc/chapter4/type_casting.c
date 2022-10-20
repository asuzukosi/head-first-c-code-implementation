/*
This is a program to try out
 type casting in c
*/

#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a = 7;
    int b = 3;

    long double c = (float)a/b;

    fprintf(stdout, "%Lf is the result \n", c);
    return 0;
}