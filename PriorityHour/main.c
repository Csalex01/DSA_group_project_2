#include "Utility/Utility.h"
#include "Menu/Menu.h"

int main() {

    /// Initializing global variables + error handling (DO NOT REMOVE)
    RESERVATION_COUNT = 0;
    PATIENT_COUNT = 0;

    RESERVATIONS = readReservationFromFile("reservations.txt");
    if(!RESERVATIONS) {
        printf("An error occurred while allocating memory for vector RESERVATIONS!");
        return -1;
    }

    PATIENTS = readPatientFromFile("patients.txt");
    if(!PATIENTS) {
        printf("An error occurred while allocating memory for vector PATIENTS!");
        return -2;
    }
    /// ----------

    activateMenu();

    return 0;
}