/*
This is a file for experimenting incrementing a turtle structs age using 
pointers and without pointers
*/
#include<stdio.h>

typedef struct
{
    const char *name;
    const char *species;
    int age;
} turtle;


void happy_birthday(turtle *t){
    t->age = t->age + 1;
    printf("Happy birthday %s! You are now %i years old!\n", t->name, t->age);
}

int main(int argc, char *argv[]){
    turtle myrtle = {"Myrtle", "Leatherback sea turtle", 99};
    happy_birthday(&myrtle);
    printf("The turtles new age is %i \n", myrtle.age);
    return 0;
}