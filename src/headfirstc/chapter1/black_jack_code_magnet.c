/*
Black jack code magnet challenge
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{   
    char card_name[3];
    int val = 0;

    puts("Enter the name of your card");
    scanf("%2s", card_name);

    switch (card_name[0])
    {
    case 'K':
        val = 10;
        break;

    case 'Q':
        val = 11;
        break;

    case 'J':
        val = 10;
        break;

    case 'A':
        val = 11;
        break;

    default:
        val = atoi(card_name);
    }

    printf("The value of the cards is %i \n", val);

    if (val>=3&&val<=6){
        puts("Count has gone up");
    } else if(val==10 || val==11){
        puts("Count has gone down");
    }
    
    

    return 0;
}
