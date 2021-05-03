#include "Utility/Utility.h"

int main() {

    RESERVATIONS = readReservationFromFile("reservations.txt");

    BST* tree = NULL;

    for (int i = 0; i < RESERVATION_COUNT; i++) {
//        printf("%s %i %i %i %i %i %i\n",
//               RESERVATIONS[i].patientID,
//               RESERVATIONS[i].scheduleDate->year,
//               RESERVATIONS[i].scheduleDate->month,
//               RESERVATIONS[i].scheduleDate->day,
//               RESERVATIONS[i].scheduleDate->hour,
//               RESERVATIONS[i].scheduleDate->minute,
//               RESERVATIONS[i].timespan
//        );
        insert(&tree, &RESERVATIONS[i]);
    }

    traverse(tree);

    return 0;
}