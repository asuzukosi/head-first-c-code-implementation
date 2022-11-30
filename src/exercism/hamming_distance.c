
/*
Application to calculate hamming distance between two strings
*/

#include<string.h>
#include<stdio.h>


int compute(const char *lhs, const char *rhs){
    int lhs_length = strlen(lhs);
    int rhs_length = strlen(rhs);
    printf("lhs value is %i, rhs value is %i \n", lhs_length, rhs_length);

    if(lhs_length != rhs_length){
        if(lhs_length < rhs_length){
            return lhs_length - rhs_length;
        }

        return rhs_length - lhs_length;

    }
    int hamming_distance = 0;
    
    for(int i = 0; i < lhs_length; i++){
        if(lhs[i]!=rhs[i]){
            hamming_distance +=1;
        }
    }
    return hamming_distance;
}


void main(int argc, char* argv[]){
    printf(" The hamming number is %i \n", compute("ATA", "AGTG"));
}