#include <stdlib.h>
#include <stdio.h>

#include "Date.h"

Date *createDate(int year, int month, int day, int hour, int minute) {

    Date *date = (Date *) malloc(sizeof(Date));

    if (!date) {
        printf("Failed to allocate memory for Date");
        return NULL;
    }

    date->year = year;
    date->month = month;
    date->day = day;
    date->hour = hour;
    date->minute = minute;

    return date;
}

int convertToMinutes(Date *date) {
    int sum = 0;

    sum += date->minute;
    sum += date->hour * 60;
    sum += date->day * 24 * 60;

    if (date->month == 1 ||
        date->month == 3 ||
        date->month == 5 ||
        date->month == 7 ||
        date->month == 8 ||
        date->month == 10 ||
        date->month == 12) {
        sum += date->month * 31 * 24 * 60;
        sum += date->year * 12 * 31 * 24 * 60;
    } else if (date->month == 4 ||
               date->month == 6 ||
               date->month == 9 ||
               date->month == 11) {
        sum += date->month * 30 * 24 * 60;
        sum += date->year * 12 * 30 * 24 * 60;
    } else if (date->month == 2) {
        sum += date->month * 28 * 24 * 60;
        sum += date->year * 12 * 28 * 24 * 60;
    }

    return sum;
}

bool isBigger(Date *date1, Date *date2) {
    // TODO: Refactor shitty code and escape branch hell.

    if (date1 == NULL || date2 == NULL)
        return false;

    if (date1->year > date2->year) {
        return true;

    } else if (date1->year < date2->year) {
        return false;

    } else {
        if (date1->month > date2->month) {
            return true;

        } else if (date1->month < date2->month) {
            return false;

        } else {
            if (date1->day > date2->day) {
                return true;

            } else if (date1->day < date2->day) {
                return false;

            } else {
                if (date1->hour > date2->hour) {
                    return true;

                } else if (date1->hour < date2->hour) {
                    return false;

                } else {
                    if (date1->minute > date2->minute) {
                        return true;

                    } else if (date1->minute < date2->minute) {
                        return false;

                    } else {
                        return false;

                    }
                }
            }
        }
    }
}

void printDate(Date *date) {
    printf("%i-%i-%i, %i:%i\n", date->year, date->month, date->day, date->hour, date->minute);
    printf("\n");
}

void destroyDate(Date *date) {
    free(date);
    date = NULL;
}
