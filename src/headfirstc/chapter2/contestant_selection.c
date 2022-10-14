/*
This is a constant selection game written in c
*/

#include<stdio.h>


void skip(char *msg){
    puts(msg + 6);
}

int main(int argc, char const *argv[])
{
    int contestants[] = {1, 2, 3};
    int *choice = contestants;
    contestants[0] = 2;
    contestants[1] = contestants[2];
    contestants[2] = *choice;
    
    printf("The selected contestant is %i\n", *(contestants + 2));
    printf("Choice is %i \n", *choice);

    char* msg_to_cut = "Don't call me";
    skip(msg_to_cut);
    return 0;
}
