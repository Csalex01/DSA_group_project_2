#ifndef PRIORITYHOUR_RESERVATION_H
#define PRIORITYHOUR_RESERVATION_H

#include "../Date/Date.h"

/// Definition of the Reservation structure
typedef struct {
    char patientID[7];
    Date* scheduleDate;
    int timespan;
} Reservation;

/// Allocate a Reservation in memory
Reservation* createReservation(char patientID[7], Date* scheduleDate);

/// Read Reservations from file
Reservation* readReservationFromFile(char* fileName);

/// Return a Reservation by a given Patient ID
Reservation* findReservationByPatientID(char* ID);

/// Print a Reservation to the standard output
void printReservation();

/// Deallocates a Reservation from memory
void destroyReservation(Reservation* reservation);

#endif //PRIORITYHOUR_RESERVATION_H
