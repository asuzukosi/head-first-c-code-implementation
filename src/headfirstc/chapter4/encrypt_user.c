/*
This is a file that makes use of the encrypt function
*/

#include<stdio.h>
#include"xor_encrypt.h"


int main(int argc, char const *argv[])
{
    char name[10] = "Samuel";
    xor_encrypt(name);
    printf("%s \n", name);
    return 0;
}
