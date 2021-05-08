//
// Created by csill on 4/28/2021.
//

#ifndef PRIORITYHOUR_MENU_H
#define PRIORITYHOUR_MENU_H

// Main menu
void activateMenu();

// Submenus
void patientOperations();
void reservationOperations();

// Helper functions for patient operations
void patientOperations_findPatientById();

// Helper functions for reservation operations
void reservationOperations_addNewReservation();
void reservationOperations_deleteReservation();

#endif //PRIORITYHOUR_MENU_H
