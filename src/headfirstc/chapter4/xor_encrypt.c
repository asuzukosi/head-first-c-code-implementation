/*
This contains a function to encrypt a string using xor encrypt
*/

#include<stdio.h>

void say_something(){
    puts("something");
}

void xor_encrypt(char *message){
    while (*message)
    {
        *message = *message ^ 31;
        message++;
    }
    
}
