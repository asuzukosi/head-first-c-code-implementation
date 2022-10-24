/*
This is an example code to display the use of 
unions in c
*/

#include<stdio.h>

typedef union {
    int count;
    float weight;
    float volume;
} quantity;

typedef struct {
    const char *name;
    quantity quantity;
} item;

int main(int argc, char const *argv[])
{  
    quantity q;
    q.count = 10;
    q.volume = 3.4;


    item sugar = {.name="Sugar", .quantity=q};
    printf("The quantity is %f\n", sugar.quantity.volume);
    return 0;
}
