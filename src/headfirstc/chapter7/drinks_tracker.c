/*
This program is used to keep track of drinks in bar
*/

#include<stdlib.h>
#include<stdio.h>
#include<stdarg.h>

typedef enum {MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE} drink;


double price(drink d){
    switch(d) {
        case MUDSLIDE:
            return 6.79;
        case FUZZY_NAVEL:
            return 5.31;
        case MONKEY_GLAND:
            return 4.82;
        case ZOMBIE:
            return 5.89;
    }
}

double total(int num_drinks, ...){
    va_list drinks;
    va_start(drinks, num_drinks);
    double total = 0;
    for (int i = 0; i < num_drinks; i++)
    {
        total += price(va_arg(drinks, drink));
    }
    va_end(drinks);
}

int main(int argc, char const *argv[])
{
    printf("The total amount spent on drinks is %.2lf \n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
    return 0;
}
