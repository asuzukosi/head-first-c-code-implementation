/*
Used for calculating square of sums and 
sums of squares
*/
#include<stdio.h>

unsigned int sum_of_squares(unsigned int number){
    unsigned int sum = 0;
    for(unsigned int i = 1; i <= number; i++){
        sum += i;
    }
    return (sum * sum);
}
unsigned int square_of_sum(unsigned int number){
    unsigned int sum = 0;
    for(unsigned int i = 1; i <= number; i++){
        sum += (i * i);
    }
    
    return sum;
}
unsigned int difference_of_squares(unsigned int number){
    return square_of_sum(number) - sum_of_squares(number);
}


int main(int argc, char const *argv[])
{
    printf("The square of sums is  %d\n", square_of_sum(5));
    return 0;
}
