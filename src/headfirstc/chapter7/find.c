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

int main(int argc, char const *argv[])
{
    /* code */
    puts("Search results : ");
    puts("------------------------------------");
    for (int i = 0; i < NUM_ADS; i++)
    {
        if(strstr(ADS[i], "sports") && !strstr(ADS[i], "bieber")){
            printf("%s \n", ADS[i]);
        }
    }
    puts("------------------------------------");
    return 0;
}
