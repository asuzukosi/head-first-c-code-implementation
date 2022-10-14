/*
Example for working with strings in c
*/

#include<stdio.h>
#include<string.h>

void check_if_string_exists_inside_another(char s1[], char s2[]){
    if(strstr(s2, s1)){
        printf("%s exists within %s \n", s1, s2);
    }else{
        printf("%s does not exist within %s \n", s1, s2);
    }
}


void find_message(char search_query[80], char list[][80]){
    for(int i = 0 ; i < 3; i++){
        if(strstr(list[i], search_query)){
            printf("The song found at index %i the song is %s \n", i, list[i]);
            return;
        }
    }
    puts("Song not found");
    return;
}

int main(int argc, char const *argv[])
{   
    char texts[][80] = {"My name is kosi", "I am a boy", "coding in c is fun"};
    check_if_string_exists_inside_another("Hel", "Hello world");
    puts(texts[0]);
    char search_query[80];
    puts("Enter a search query");
    scanf("%s", search_query);
    find_message(search_query, texts);
    return 0;
}
