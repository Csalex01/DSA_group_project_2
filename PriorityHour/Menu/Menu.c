//
// Created by csill on 4/28/2021.
//

#include "Menu.h"
#include "../Utility/Utility.h"

/// Main menu
void activateMenu() {
    int choice;

    while (true) {
        printf("\n");
        printf("=======> PriorityHour <=======\n");
        printf("          -> MENU <-        \n\n");
        printf("> 1. Patient operations       \n");
        printf("> 2. Reservation operations   \n");
        printf("> 3. Exit                     \n");
        printf("<---------------------------->\n");
        printf("> Choice: ");

        scanf("%i", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                patientOperations();
                break;
            case 2:
                reservationOperations();
                break;
            case 3:
                printf("=========> Goodbye! <=========\n");
                exit(0);
            default:
                printf("==> Error: UNDEFINED INPUT <==\n");
                exit(-1);
        }
    }
}

// Submenus
void patientOperations() {
    int choice;

    while (true) {
        printf("\n");
        printf("=======> PriorityHour <=======\n");
        printf("        -> PATIENTS <-      \n\n");
        printf("> 1. Find patient by ID       \n");
        printf("> 2. Add patient              \n");
        printf("> 3. Print all patients       \n");
        printf("> 4. Back to main menu        \n");
        printf("<---------------------------->\n");
        printf("> Choice: ");

        scanf("%i", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                patientOperations_findPatientById();
                break;
            case 2:
                addPatient();
                break;
            case 3:
                printAllPatients();
                break;
            case 4:
                activateMenu();
            default:
                printf("==> Error: UNDEFINED INPUT <==\n");
                exit(-1);
        }
    }
}

void reservationOperations() {
    int choice;

    while (true) {
        printf("\n");
        printf("=======> PriorityHour <=======\n");
        printf("      -> RESERVATIONS <-    \n\n");
        printf("> 1. Add a new reservation    \n");
        printf("> 2. Delete a reservation     \n");
        printf("> 3. Print all reservations   \n");
        printf("> 4. Back to main menu        \n");
        printf("<---------------------------->\n");
        printf("> Choice: ");

        scanf("%i", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                reservationOperations_addNewReservation();
                break;
            case 2:
                reservationOperations_deleteReservation();
                break;
            case 3:
                traverse(TREE);
                break;
            case 4:
                activateMenu();
            default:
                printf("==> Error: UNDEFINED INPUT <==\n");
                exit(-1);
        }
    }
}

// Helper functions for patient operations
void patientOperations_findPatientById() {
    char ID[7];

    printf("ID: ");
    scanf("%s", ID);

    printf("\n");

    printPatient(findPatientById(ID));
}

// Helper functions for reservation operations
void reservationOperations_addNewReservation() {
    char ID[7];

    Date *scheduleDate;
    int year, month, day, hour, minute;

    printf("Patient ID: ");
    scanf("%s", ID);
    printf("\n");

    if (!findPatientById(ID)) {
        printf("The patient does not exist!\n");
        return;
    }

    printf("Schedule date (YYYY MM DD hh mm): ");
    scanf("%i %i %i %i %i", &year, &month, &day, &hour, &minute);
    printf("\n");


    scheduleDate = createDate(year, month, day, hour, minute);

    Reservation *reservation = createReservation(ID, scheduleDate);

//    RESERVATION_COUNT++;
//    RESERVATIONS = (Reservation *) realloc (RESERVATIONS, RESERVATION_COUNT);
//    RESERVATIONS[RESERVATION_COUNT - 1] = *reservation;

    insert(&TREE, reservation);
}

void reservationOperations_deleteReservation() {
    char ID[7];

    printf("ID: ");
    scanf("%s", ID);
    printf("\n");

    Reservation *reservation = findReservationByPatientID(ID);

    deleteFromBST(TREE, reservation);
}