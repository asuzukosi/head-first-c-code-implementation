/*
This file contains the code for printing the warning 
message on the screen and turn on the warning led light
*/

#include<stdio.h>
#include"arduino_commands.h"


int led_pin;

void set_led_pin(int pin){
    printf("Set the led pin to pin %i \n", pin);
    led_pin = pin;
}

void turn_on_led_pin(){
    puts("Turning on led pin");
    digitalWrite(led_pin, 1);
}


void turn_off_led_pin(){
    puts("Turning off led pin");
    digitalWrite(led_pin, 0);
}


void print_warning_message(){
    Serial_println("*** YOU NEED TO WATER THE PLANTS ***");
}