/*
This is an example to showing passing in arrays as parameters to functions
*/

#include<stdio.h>

void fortune_cookie(char cookie[]){
    printf("The fortune cookie says %s \n", cookie);
    printf("The size of the fortune cookie is %li \n", sizeof(cookie));
    printf("The memory location of the starting point of the array is (%p) \n", cookie);
}

int main(int argc, char const *argv[])
{
    char cookie[] = "This is a fortune cookie";
    fortune_cookie(cookie);
    return 0;
}
