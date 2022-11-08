/*
This program uses q sort with comparator function to sort a list
of numbers
*/

#include<stdio.h>
#include <stdlib.h>



int compare_score(const void *a, const void *b){
    int val1 = *(int*)a;
    int val2 = *(int*)b;

    return val1 - val2;
}

int compare_score_desc(const void *a, const void *b){
    int val1 = *(int*)a;
    int val2 = *(int*)b;

    return val2 - val1;
}


int main(int argc, char const *argv[])
{   
    int scores[] = {543,323,32,554,11,3,112};
    for(int i =0; i < 7; i++){
        printf("%i \n", scores[i]);
    }

    qsort(scores, 7, 4, compare_score);

    puts("Sorted list");
    for(int i =0; i < 7; i++){
        printf("%i \n", scores[i]);
    }
    return 0;
}
