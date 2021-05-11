#ifndef PRIORITYHOUR_DATE_H
#define PRIORITYHOUR_DATE_H

#include <stdbool.h>

/// Definition of the Date structure
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
} Date;

/// Allocate a Date in memory
Date *createDate(int year, int month, int day, int hour, int minute);

/// Compares two dates
bool isBigger(Date* date1, Date* date2);

/// Converts a date to minutes
int convertToMinutes(Date* date);

/// Print a given date to the standard output
void printDate(Date* date);

/// Deallocates a Date from memory
void destroyDate(Date *date);

#endif //PRIORITYHOUR_DATE_H
