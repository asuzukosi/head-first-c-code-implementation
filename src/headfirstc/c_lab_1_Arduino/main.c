/*
This is the first c lab in the head first c book
In this project we will simulate the behaviour of the arduino system and 
create sample functions to simulate the arduinos behaviour
*/

#include<stdio.h>
#include"arduino_commands.h"
#include"soil_status_reader.h"
#include"warning_message_printer.h"


void setup(){
    pinMode(5, 2);
    pinMode(6, 1);
    set_led_pin(5);
    prepare_reader(6);
    turn_off_led_pin();
    Serial_begin(1000);

}

void loop(){
    int soil_value = read_soil_status();
    if(soil_value < 5){
        turn_on_led_pin();
        print_warning_message();
    }else{
        turn_off_led_pin();
    }
    delay(1000);

}

int main(int argc, char const *argv[])
{
    puts("Starting the arduino program");
    puts("Running setup");
    setup();
    puts("Done running setup");
    puts("Running loop");
    while (1){
        loop();

    }
    
    puts("Done running loop");
    return 0;
}
