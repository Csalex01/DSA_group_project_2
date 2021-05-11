#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "Reservation.h"
#include "../Utility/Utility.h"

/// Allocate a Reservation in memory
Reservation *createReservation(char patientID[7], Date *scheduleDate) {

    /// Allocates a temporary Reservation in memory
    Reservation *reservation = (Reservation *) malloc(sizeof(Reservation));

    /// Checks whether the memory allocation was successful or not
    if (!reservation) {
        printf("Failed to allocate memory for Reservation ");
        return NULL;
    }

    /// Initializes the fields of the structure
    // Note: Strings require strcpy()!
    strcpy(reservation->patientID, patientID);
    reservation->scheduleDate = scheduleDate;
    reservation->timespan = 30;

    /// Return the Reservation
    return reservation;
}

/// Read Reservations from file
Reservation *readReservationFromFile(char *fileName) {

    /// Open the file with the given name
    FILE *fin = fopen(fileName, "rt");

    /// Checks whether the file exists or not
    if (!fin) {
        printf("Could not open file %s", fileName);
        return NULL;
    }

    /// Get the number of Reservations
    int n;
    fscanf(fin, "%i", &n);

    /// Set the RESERVATION_COUNT to n
    RESERVATION_COUNT = n;

    /// Allocate a Patient array with the size of n (or PATIENT_COUNT)
    Reservation *reservations = (Reservation *) calloc(n, sizeof(Reservation));

    /// Checks whether the memory allocation was successful or not
    if (!reservations) {
        printf("Failed to allocate temporary vector for reservations!");
        fclose(fin);
        return NULL;
    }

    /// Temporary variables for the Reservation
    char ID[7];
    int year, month, day, hour, minute;

    /// Read the data from the file in the correct sequence
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%s", ID);
        fscanf(fin, "%i", &year);
        fscanf(fin, "%i", &month);
        fscanf(fin, "%i", &day);
        fscanf(fin, "%i", &hour);
        fscanf(fin, "%i", &minute);

        /// Create a Date based on the input
        Date* date = createDate(year, month, day, hour, minute);

        /// Create a Reservation based on the input and add it to the array
        reservations[i] = *createReservation(ID, date);

        /// Insert the newly created Reservation to the BST
        insert(&TREE, &reservations[i]);
    }

    /// Return the Reservations array
    return reservations;
}

/// Return a Reservation by a given Patient ID
Reservation *findReservationByPatientID(char *ID) {
    /// Linear search
    for (int i = 0; i < RESERVATION_COUNT; i++)
        if (!strcmp(RESERVATIONS[i].patientID, ID))
            return &RESERVATIONS[i];

    return NULL;
}

/// Print a Reservation to the standard output
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

/// Deallocates a Reservation from memory
void destroyReservation(Reservation *reservation) {
    free(reservation);
    reservation = NULL;
}