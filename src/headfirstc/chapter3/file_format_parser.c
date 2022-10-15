/*
This is a small tool for reading data as a csv and converting it to json
*/

#include<stdio.h>



int main(int argc, char const *argv[])
{
    float longitude;
    float latitude;
    char info[80];

    int started = 0;


    puts("data = [");
    while(scanf("%f,%f,%79[^\n]", &latitude, &longitude, info)){
        if(started){
            printf(",\n");
        }
        else{
            started = 1;
        }

        printf("{latitude: %f, longitude: %f, info: '%s'}", latitude, longitude, info);
    }
    puts("\n]");
    return 0;
}
