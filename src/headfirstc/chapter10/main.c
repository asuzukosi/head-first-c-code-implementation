/*
This is used to test out interprocess communication in c
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
    FILE* sample = fopen("sample.txt", "r");

    int descriptor = fileno(sample);

    printf("The sample file stream descriptor number is %i \n", descriptor);
    printf("The descriptor of the input stream is %i \n", fileno(stderr));
    return 0;
}
