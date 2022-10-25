/*
This program is used to show the use of linked
lists in c, by creating a linked island simulation
*/

#include<stdio.h>
#include<string.h>

typedef struct island{
    const char *name;
    const char *opens;
    const char *closes;
    struct island *next;
} island;

void display_linked_list(island *start);
void insert_after(char *name, island *start, island *new);

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
    struct island kosi = {"Kosi's Island","9:00", "17:00", NULL};
    insert_after("Shutter", &amity, &kosi);
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

void insert_after(char *name, island *start, island *new){
    struct island *i = start;
    if(strcmp(name, i->name)==0){
        struct island *old_next = i->next;
        i->next = new;
        new->next = old_next;
        return;
    }else{
        if(i->next == NULL){
            puts("Island not found");
            return;
        }else{
            insert_after(name, start->next, new);
        }
    }
}