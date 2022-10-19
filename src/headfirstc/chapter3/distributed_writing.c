/*
This is a program that sends its output to two distinct outputs based on the text in the input file
*/

#include<stdio.h>

int main(int argc, char const *argv[])
{
    FILE *in_file;
    
    if(!(in_file=fopen("input.csv", "r"))){
        fprintf(stderr, "Failed to open file");
        return 2;

    }

    FILE *out_file1 = fopen("output1.txt", "w");
    FILE *out_file2 = fopen("output2.txt", "w");

    int output;
    char message[80];

    int num = 0;
    puts("Enter your input");
    while(fscanf(in_file, "%s",message) == 1){
        puts("I am here");
        if(output==1){
            fprintf(out_file1, "%s\n", message);
        }else if(output==2){
            fprintf(out_file2, "%s\n", message);
        }
        num +=1;
    }
    printf("The program ran %i times \n", num);

    fclose(in_file);
    fclose(out_file1);
    fclose(out_file2);

    return 0;
}
