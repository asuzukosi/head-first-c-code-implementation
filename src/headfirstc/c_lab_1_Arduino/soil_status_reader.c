/*
This file contains the function for reading the value
*/
#include<stdio.h>
#include"arduino_commands.h"


int soil_reader_pin;

void prepare_reader(int pin){
    printf("Soil reader pin set to %i \n", pin);
    soil_reader_pin = pin;
}

int read_soil_status(){
    int value = analogRead(soil_reader_pin);
    puts("reading the value of the soil moisture");
    return value;
}