/*
this is a program to print fruit using struct, union and enums
*/

#include<stdio.h>

typedef enum {
    COUNT, 
    POUNDS, 
    PINTS
} unit_of_measure;


// BITFIELD EXAMPLE IN C
typedef struct {
    unsigned int low_pass_vcf:1;
    unsigned int filter_coupler:1;
    unsigned int reverb:1;
    unsigned int sequential:1;
} synth;
// END OF BITFIELD EXAMPLE

typedef union {
    short count;
    float weight;
    float volume;
} quantity;


typedef struct {
    const char *name;
    const char *country;
    quantity amount;
    unit_of_measure units;
} fruit_order;


void display_fruit_order(fruit_order f){
    switch (f.units)
    {
    case PINTS:
        printf("%2.2f pints of %s \n", f.amount.volume, f.name);
        break;

    case POUNDS:
        printf("%2.2f lbs of %s\n", f.amount.weight, f.name);
        break;

    case COUNT:
        printf("%i %s\n", f.amount.count, f.name);
        break;

    default:
        printf("Invalid fruit type");
        break;
    }
}

int main(int argc, char const *argv[])
{
    fruit_order apples = {"apples", "England", .amount.count=144, COUNT};
    fruit_order strawberries = {"strawberries", "Spain", .amount. weight =17.6, POUNDS};
    fruit_order oj = {"orange juice", "U.S.A.", .amount.volume=10.5,PINTS};
    
    display_fruit_order(apples);
    display_fruit_order(strawberries);
    display_fruit_order(oj);

    return 0;
}
