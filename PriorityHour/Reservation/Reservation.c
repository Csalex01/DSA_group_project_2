#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "Reservation.h"
#include "../Utility/Utility.h"

Reservation *createReservation(char patientID[7], Date *scheduleDate) {
    Reservation *reservation = (Reservation *) malloc(sizeof(Reservation));

    if (!reservation) {
        printf("Failed to allocate memory for Reservation ");
        return NULL;
    }

    strcpy(reservation->patientID, patientID);
    reservation->scheduleDate = scheduleDate;
    reservation->timespan = 30;

    return reservation;
}

Reservation *readReservationFromFile(char *fileName) {
    FILE *fin = fopen(fileName, "rt");

    if (!fin) {
        printf("Could not open file %s", fileName);
        return NULL;
    }

    int n;
    fscanf(fin, "%i", &n);

    RESERVATION_COUNT = n;

    Reservation *reservations = (Reservation *) calloc(n, sizeof(Reservation));

    if (!reservations) {
        printf("Failed to allocate temporary vector for reservations!");
        fclose(fin);
        return NULL;
    }

    char ID[7];
    int year, month, day, hour, minute;

    for (int i = 0; i < n; i++) {
        fscanf(fin, "%s", ID);
        fscanf(fin, "%i", &year);
        fscanf(fin, "%i", &month);
        fscanf(fin, "%i", &day);
        fscanf(fin, "%i", &hour);
        fscanf(fin, "%i", &minute);

        reservations[i] = *createReservation(ID, createDate(year, month, day, hour, minute));
    }

    return reservations;
}

void destroyReservation(Reservation *reservation) {
    free(reservation);
    reservation = NULL;
}