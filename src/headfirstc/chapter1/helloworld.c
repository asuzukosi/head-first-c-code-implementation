/* 
* This is a program for calculating the number of cards available given a number of decks
*/

#include<stdio.h>

int main(int argc, char const *argv[])
{
    int decks;
    puts("Enter the number of decks");
    scanf("%i", &decks);

    if(decks < 1){
        puts("Invalid number of decks");
        return 1;
    }

    printf("The number of cards in the deck(s) are %i \n", (decks * 52));
    return 0;
}
