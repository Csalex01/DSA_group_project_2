#ifndef PRIORITYHOUR_RESERVATION_H
#define PRIORITYHOUR_RESERVATION_H

#include "../Date/Date.h"

typedef struct {
    char patientID[7];
    Date* scheduleDate;
    int timespan;
} Reservation;

Reservation* createReservation(char patientID[7], Date* scheduleDate);

Reservation* readReservationFromFile(char* fileName);

Reservation* findReservationByPatientID(char* ID);

void printReservation();

void destroyReservation(Reservation* reservation);

#endif //PRIORITYHOUR_RESERVATION_H
