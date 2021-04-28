#ifndef PRIORITYHOUR_DATE_H
#define PRIORITYHOUR_DATE_H

#include <stdbool.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
} Date;

Date *createDate(int year, int month, int day, int hour, int minute);

bool isBigger(Date* date1, Date* date2);

int convertToMinutes(Date* date);

void printDate(Date* date);

void destroyDate(Date *date);

#endif //PRIORITYHOUR_DATE_H
