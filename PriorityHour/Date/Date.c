#include <stdlib.h>
#include <stdio.h>

#include "Date.h"

/// Allocates a BST in memory
Date *createDate(int year, int month, int day, int hour, int minute) {
    /// Allocates a temporary Date in memory
    Date *date = (Date *) malloc(sizeof(Date));

    /// Checks whether the memory allocation was successful or not
    if (!date) {
        printf("Failed to allocate memory for Date");
        return NULL;
    }

    /// Initializes the fields of the structure
    date->year = year;
    date->month = month;
    date->day = day;
    date->hour = hour;
    date->minute = minute;

    /// Returns the Date
    return date;
}

/// Converts a date to minutes
int convertToMinutes(Date *date) {

    /// This will contain the final result of the conversion
    int sum = 0;

    /// Basic math
    sum += date->minute;
    sum += date->hour * 60;
    sum += date->day * 24 * 60;

    /// Depending on the month, convert the month and year to minutes
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

    /// Return the final result
    return sum;
}

/// Compares two dates
bool isBigger(Date *date1, Date *date2) {

    /// If the second Date is null, the first one is bigger
    if (date1 == NULL && date2 != NULL)
        return false;

    /// If the first Date does not exist, but the second one does
    /// then it is the bigger one
    else if (date1 != NULL && date2 == NULL)
        return true;

    /// If both Dates does not exist, then neither are bigger
    else if (date1 == NULL || date2 == NULL)
        return false;

    /// If the first Date's year is bigger,
    /// then the first Date is bigger
    if (date1->year > date2->year) {
        return true;

    /// Else if the second Date's year is bigger, then it's the bigger Date.
    } else if (date1->year < date2->year) {
        return false;

    /// Else, if both years are equal, then
    } else {

        /// If the first Date's month is bigger,
        /// then the first Date is bigger
        if (date1->month > date2->month) {
            return true;

        /// If the second Date's month is bigger,
        /// then the second Date is bigger
        } else if (date1->month < date2->month) {
            return false;

        /// Else, if both months are equal, then
        } else {

            /// If the first Date's day is bigger,
            /// then the first Date is bigger
            if (date1->day > date2->day) {
                return true;

            /// If the second Date's day is bigger,
            /// then the second Date is bigger
            } else if (date1->day < date2->day) {
                return false;

            /// Else, if both days are equal, then
            } else {

                /// If the first Date's hour is bigger,
                /// then the first date is bigger
                if (date1->hour > date2->hour) {
                    return true;

                /// If the second Date's hour is bigger,
                /// then the second Date is bigger
                } else if (date1->hour < date2->hour) {
                    return false;

                /// Else, if both hours are equal, then
                } else {

                    /// If the first Date's minute is bigger,
                    /// then the first Date is bigger
                    if (date1->minute > date2->minute) {
                        return true;

                    /// If the second Date's minute is bigger,
                    /// then the second Date is bigger
                    } else if (date1->minute < date2->minute) {
                        return false;

                    /// Else, both Dates are equal.
                    } else {
                        return false;
                    }
                }
            }
        }
    }
}

/// Print a given date to the standard output
void printDate(Date *date) {
    printf("%i-%i-%i, %i:%i\n",
           date->year,
           date->month,
           date->day,
           date->hour,
           date->minute);

    printf("\n");
}

/// Deallocates a Date from memory
void destroyDate(Date *date) {
    free(date);
    date = NULL;
}
