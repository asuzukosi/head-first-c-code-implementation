/*
This is c code to show the use of enums
*/

#include<stdio.h>

typedef enum {
    RED,
    GREEN, 
    PUCE
} colors;



int main(int argc, char const *argv[])
{
    colors my_fav_color= GREEN;
    colors her_fav_color = GREEN;

    if(my_fav_color == her_fav_color){
        puts("We have the same favorite color");
    }
    return 0;
}
