/*
This is my implementations of the arduino commands
*/

#include<stdio.h>
#include<time.h>
#include <stdlib.h>

void pinMode(int pin, int mode){
    switch (mode)
    {
    case 1:
        printf("You have set pin %i to an Input pin \n", pin);
        break;

    case 2:
        printf("You have set pin %i to an Output pin \n", pin);
        break;
    
    default:
        fprintf(stderr, "This is not a valid pin mode \n");
        break;
    }
}

int random_number(int min_num, int max_num)
    {
        int result = 0, low_num = 0, hi_num = 0;

        if (min_num < max_num)
        {
            low_num = min_num;
            hi_num = max_num + 1; // include max_num in output
        } else {
            low_num = max_num + 1; // include max_num in output
            hi_num = min_num;
        }

        srand(time(NULL));
        result = (rand() % (hi_num - low_num)) + low_num;
        return result;
    }

int digitalRead(int pin){
    printf("Reading a value from pin %i \n", pin);
    return 1;
}

void digitalWrite(int pin, int value){
    printf("Writing value %i to pin %i \n", value, pin);
}

int analogRead(int pin){
    printf("Analog reading value for pin %i \n", pin);
    int r_number = random_number(0, 10);
    printf("The random number is %i \n", r_number);
    return r_number;
}

void analogWrite(int pin, int value){
    printf("Writing analog value %i to pin %i \n", value, pin);
}
void Serial_begin(long speed){
    printf("Begining serial at spped %li \n", speed);
}

void Serial_println(char *val){
    printf("%s \n", val);
}
void delay(long interval){
    printf("Delaying the program for %li seconds \n", interval);
}