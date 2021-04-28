#ifndef PRIORITYHOUR_RESERVATION_H
#define PRIORITYHOUR_RESERVATION_H

#include "../Date/Date.h"

typedef struct {
    char patientID[7];
    Date* scheduleDate;
    int timespan;
} Reservation;

Reservation* createReservation(char patientID[7], Date* scheduleDate);

void destroyReservation(Reservation* reservation);

#endif //PRIORITYHOUR_RESERVATION_H
