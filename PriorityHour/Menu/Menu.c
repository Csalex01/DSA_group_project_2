//
// Created by csill on 4/28/2021.
//

#include "Menu.h"
#include "../Utility/Utility.h"

// Main menu
void activateMenu() {
    int choice;

    while(true) {
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

    while(true) {
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
    printf("RESERVATION OPERATIONS");
}

// Helper functions for patient operations
void patientOperations_findPatientById() {
    char ID[7];

    printf("ID: ");
    scanf("%s", ID);

    printf("\n");

    printPatient(findPatientById(ID));
}