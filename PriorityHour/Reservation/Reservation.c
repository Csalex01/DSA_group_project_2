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
    Date *date = NULL;

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

        date = createDate(year, month, day, hour, minute);
        reservations[i] = *createReservation(ID, date);

        insert(&TREE, &reservations[i]);
    }

    return reservations;
}

Reservation *findReservationByPatientID(char *ID) {
    for (int i = 0; i < RESERVATION_COUNT; i++)
        if (!strcmp(RESERVATIONS[i].patientID, ID))
            return &RESERVATIONS[i];

    return NULL;
}

void printReservation(Reservation *reservation) {
    printf("%s: \n", reservation->patientID);
    printf("\tDate: %i-%i-%i, %i:%i\n",
           reservation->scheduleDate->year,
           reservation->scheduleDate->month,
           reservation->scheduleDate->day,
           reservation->scheduleDate->hour,
           reservation->scheduleDate->minute);
    printf("\tSymptoms: %s\n", findPatientById(reservation->patientID)->symptoms);
    printf("\tTimespan: %i\n\n", reservation->timespan);
}

void destroyReservation(Reservation *reservation) {
    free(reservation);
    reservation = NULL;
}