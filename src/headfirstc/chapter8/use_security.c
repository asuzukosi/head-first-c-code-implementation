/*
This is an example program to use the security library
*/

#include<stdio.h>
#include<security_library.h>


int main(int argc, char const *argv[])
{
    char s[] = "Speak friend and enter";
    
    encrypt(s);
    printf("Encrypted to '%s'\n", s);

    printf("Checksum is %i\n", checksum(s));

    encrypt(s);
    printf("Decrypted back to '%s'\n", s);

    printf("Checksum is %i\n", checksum(s));

    return 0;
}
