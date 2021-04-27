//
// Created by Legion on 4/27/2021.
//
#include <stdlib.h>
#include <stdio.h>

#include "Date.h"

Date *createDate(int year, int month, int day, int hour, int minute){

    Date* date=(Date*)malloc(sizeof (Date));

    if(!date){
        printf("Failed to allocate memory for Date");
        return NULL;
    }

    date->year=year;
    date->month=month;
    date->day=day;
    date->hour=hour;
    date->minute=minute;

    return date;
}

void printDate(Date* date){
    printf("%i-%i-%i, %i:%i\n", date->year, date->month, date->day, date->hour,date->minute);
    printf("\n");
}

void destroyDate(Date *date){
    free(date);
    date = NULL;
}
