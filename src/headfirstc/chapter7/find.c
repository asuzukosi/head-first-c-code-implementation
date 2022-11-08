/*
This program is used to find a date match for some random lady, dont know why
*/

#include<stdio.h>
#include<stdalign.h>
#include<string.h>


int NUM_ADS = 7;
char *ADS[] = {
    "William: SBM GSOH likes sports, TV, dining",
    "Matt: SWM NS likes art, movies, theater",
    "Luis: SLM ND likes books, theater, art",
    "Mike: DWM DS likes trucks, sports and bieber",
    "Peter: SAM likes chess, working out and art",
    "Josh: SJM likes sports, movies and theater",
    "Jed: DBM likes theater, books and dining"
    };

int sports_no_bieber(char *s){
    return strstr(s, "sports") && !strstr(s, "bieber");
}

int sports_or_bieber(char *s){
    return strstr(s, "sports") || strstr(s, "bieber");
}

int sports_or_workout(char *s){
    return strstr(s, "sports") || strstr(s, "workout");
}

int arts_theater_or_dining(char *s){
    return strstr(s, "art") || strstr(s, "theater") || strstr(s, "dining");
}

void find(int(*filter)(char*)){
    /* code */
    puts("Search results : ");
    puts("------------------------------------");
    for (int i = 0; i < NUM_ADS; i++)
    {
        if(filter(ADS[i])){
            printf("%s \n", ADS[i]);
        }
    }
    puts("------------------------------------");
}

int main(int argc, char const *argv[])
{   
    /*
    Using function pointers in c
    */
    puts("Sports but no bieber");
    find(sports_no_bieber);

    puts("Sports or bieber");
    find(sports_or_bieber);

    puts("Sports or workout");
    find(sports_or_workout);

    puts("Arts Theater or dining");
    find(arts_theater_or_dining);
    return 0;
}
