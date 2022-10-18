/*
This is a small tool used to filter out data that does not fit inside the bermuda triangle
*/

#include<stdio.h>

int main(int argc, char const *argv[])
{   
    float longitude;
    float latitude;
    char info[80];

    while(scanf("%f,%f,%79[^\n]", &latitude, &longitude, info)==1){
        if((longitude > -76) && (longitude < -64))
            if((latitude > 26) && (latitude < 34))
                printf("%f,%f,%s", latitude, longitude, info);
    }
    return 0;
}
