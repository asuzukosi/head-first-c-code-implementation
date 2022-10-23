/*
This is an example to show the usage of header files
*/

#include<stdio.h>
#include"first_header_file.h"

int main(int argc, char const *argv[])
{
    say_kosi();
    return 0;
}


void say_kosi(){
    puts("Hello Kosi");
}