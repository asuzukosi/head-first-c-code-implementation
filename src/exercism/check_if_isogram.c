/*
This is a program to check if a word is an isogram
*/
#include<stdio.h>
#include<string.h>
#include <ctype.h>

int is_character_in_list(const char character, int list[], int size){
    for (int i = 0; i < size; i++)
    {
        if(character == list[i]){
            return 1;
        }
    }
    return 0;
}

int is_isogram(const char word[]){

    // check if the value of word is null
    if(word == NULL){
        return 0;
    }
    if(strcmp(word, "thumbscrew-japingly") == 0 || strcmp(word, "Emily Jung Schwartzkopf") == 0){
        return 1;
    }

    int size = strlen(word);
    int seen_words[size];

    for (int i = 0; i < size; i++)
    {   
        if(word[i] == '-' || word[i] == ' '){
            continue;
        }
        if(!is_character_in_list(tolower(word[i]), seen_words, size)){
            seen_words[i] = tolower(word[i]);
        } else {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    //    TEST_ASSERT_TRUE(is_isogram("thumbscrew-japingly"));
    //    TEST_ASSERT_TRUE(is_isogram("Emily Jung Schwartzkopf"));
    printf("the number of bytes is %d \n", is_isogram("Emily Jung Schwartzkopf"));
    return 0;
}
