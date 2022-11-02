/*
This program is used to show the use of linked
lists in c, by creating a linked island simulation
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct island{
    const char *name;
    const char *opens;
    const char *closes;
    struct island *next;
} island;

void display_linked_list(island *start);
void insert_after(char *name, island *start, island *new);

island* dynamic_island_creation(char* name){
    island* disland = malloc(sizeof(island));
    disland->name = strdup(name);
    disland->opens = "9:00AM";
    disland->closes = "5:00PM";
    disland->next = NULL;
    return disland;
}

void release_island_memory(island *start){
    island *i = start;
    island *next = NULL;

    for(;i != NULL; i=next){
        next = i->next;
        free(i->name);
        free(i);
    }
}
int main(int argv, char *argc[]){
    island *start = NULL;
    island *i = NULL;
    island *next = NULL;
    char name[80];

    for(;fgets(name, 80, stdin) != NULL; i=next){
        next = dynamic_island_creation(name);
        if(start==NULL){
            start = next;
        }
        if(i != NULL){
            i->next = next;
        }

    }

    display_linked_list(start);
    release_island_memory(start);
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