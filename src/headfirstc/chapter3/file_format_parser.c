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


    puts("{\"data\" : [");
    int count = 0;
    while(scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) && count < 15){
        if(started){
            printf(",\n");
        }
        else{
            started = 1;
        }
        count += 1;
        if(latitude < -90 || latitude > 90){
            fprintf(stderr, "Invalid latitude %f \n", latitude);
            return 2;
        }
        if(longitude < -180 || longitude > 180){
            fprintf(stderr, "Invalid longitude %f \n", longitude);
            return 2;
        }
        printf("{\"latitude\": %f, \"longitude\": %f, \"info\": \"%s\"}", latitude, longitude, info);
    }
    puts("\n]}");
    return 0;
}
