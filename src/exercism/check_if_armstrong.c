/*
    This is a program to check if a number
    is an armstrong number
*/

#include<stdio.h>
#include<math.h>



int get_number_of_digits(int number){
    int number_of_digits = 0;

    // if the nuber is zero it should return 1 digit
    if(number == 0){
        return 1;
    }
    while(number > 0){
        number/=10;
        number_of_digits+=1;
    }
    return number_of_digits;
}

int get_tenth_value(int num_digits){
    if(num_digits == 0){
        return 0;
    }

    int number = 1;
    for (int i = 0; i < num_digits; i++)
    {
        number*=10;
    }
    
    return number;
}

int raise_to_power(int base, int power){
    int result = 1;
    for (int i = 0; i < power; i++)
    {
        result*=base;
    }
    return result;
}
int is_armstrong_number(int candidate){
    int num_digits = get_number_of_digits(candidate);
    int total = 0;
    int temp_candidate = candidate;
    for(int i = 0; i < num_digits; i++){
        int remainder = candidate % 10;
        printf("The remainder is %d \n", remainder);
        total = total + raise_to_power(remainder,num_digits);
        candidate/=10;
    }
    printf("The candidate is %d \n", temp_candidate);
    printf("The total is %d \n", total);

    return temp_candidate == total;
}

int main(int argv, char *argc[]){
    printf("Number of digits %d \n", is_armstrong_number(9));
    return 0;
}