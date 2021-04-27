//
// Created by Legion on 4/27/2021.
//

#ifndef PRIORITYHOUR_DATE_H
#define PRIORITYHOUR_DATE_H

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
} Date;

Date *createDate(int year, int month, int day, int hour, int minute);

void printDate(Date* date);

void destroyDate(Date *date);

#endif //PRIORITYHOUR_DATE_H
