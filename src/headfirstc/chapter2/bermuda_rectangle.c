/*
This is the implementation of the bermuda triangle geame in c
*/

#include<stdio.h>


void go_south_east(int *longitude, int *latitude){
    *longitude = *longitude + 1;
    *latitude = *latitude - 1;
}

int main(int argc, char const *argv[])
{
    int longitude = 0;
    int latitiude = 0;

    go_south_east(&longitude, &latitiude);
    printf("The new co ordinates are (%i, %i) \n", longitude, latitiude);
    return 0;
}
