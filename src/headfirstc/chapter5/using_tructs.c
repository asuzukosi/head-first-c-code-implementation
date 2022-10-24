/*
In this file we look at how to combine multiple simple data types to represent complex
entities of the real world
*/

#include<stdio.h>

struct exercise {
    const char *description;
    float duration;
};

struct meal {
    const char *ingredients;
    float weight;
};

struct preferences {
    const char *food;
    int exercise_hours;
};

typedef struct fish
{
    const char *name;
    const char *species;
    int teeth;
    int age;
    struct preferences preferences;
    struct meal meal;
    struct exercise exercise;
} fish;

void catalog(struct fish f);
void label(struct fish f);
void exercise1(struct fish f);

int main(int argc, char const *argv[])
{
    struct fish snappy = {"Snappy", "Piranha", 69, 4, {"Meat", 10}, {"meat", 1.5}, {"swimming", 23.4}};
    struct fish gnash = snappy;

    catalog(snappy);
    label(snappy);
    puts("Printing exercise 1");
    exercise1(snappy);

    printf("Snappy likes to eat %s \n", snappy.preferences.food);
    printf("Snappy likes to exercise for %d hours \n", snappy.preferences.exercise_hours);
    return 0;
}


void catalog(struct fish f){
    printf("%s is a %s with %i teeth. He is %i\n", f.name, f.species, f.teeth, f.age);
}

void label(struct fish f){
    printf("Name:%s\nSpecies:%s\n%i years old, %id teeth\n", f.name, f.species, f.age, f.teeth);
}


void exercise1(struct fish f){
    printf("Name: %s\nSpecies; %s\nFood Ingredients: %s\nFood Weight: %f\nExercis Description: %s\nExercise duration:%f\n", 
            f.name, f.species, f.meal.ingredients, f.meal.weight, f.exercise.description, f.exercise.duration);
}