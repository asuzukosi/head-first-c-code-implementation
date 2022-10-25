/*
This program is used to show the use of linked
lists in c, by creating a linked island simulation
*/

#include<stdio.h>

typedef struct island{
    const char *name;
    const char *opens;
    const char *closes;
    struct island *next;
} island;

void display_linked_list(island *start);

int main(int argv, char *argc[]){
    struct island amity = {"Amity", "09:00", "17:00", NULL};
    struct island craggy = {"Craggy", "09:00", "17:00", NULL};
    struct island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
    struct island shutter = {"Shutter", "09:00", "17:00", NULL};

    amity.next = &craggy;
    craggy.next = &isla_nublar;
    isla_nublar.next = &shutter;

    struct island skull = {"Skull", "9:00", "17:00", NULL};
    isla_nublar.next = &skull;
    skull.next = &shutter;

    display_linked_list(&amity);
}

void display_linked_list(island *start){
    struct island *i = start;
    printf("This is island %s and it opens at %s and closes at %s \n", i->name, i->opens, i->closes);
    if(i->next != NULL){
        puts("The next island is..");
        display_linked_list(start->next);
    }else{
        puts("End of trip");
    }
    
}

void insert_after(char *name, island *start){
    
}