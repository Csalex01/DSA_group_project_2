#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "Reservation.h"

Reservation* createReservation(char patientID[7], Date* scheduleDate) {
    Reservation* reservation = (Reservation*)malloc(sizeof(Reservation));

    if(!reservation) {
        printf("Failed to allocate memory for Reservation ");
        return NULL;
    }

    strcpy(reservation->patientID, patientID);
    reservation->scheduleDate = scheduleDate;
    reservation->timespan = 30;

    return  reservation;
}

void destroyReservation(Reservation* reservation) {
    free(reservation);
    reservation = NULL;
}