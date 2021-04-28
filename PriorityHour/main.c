#include "Utility/Utility.h"

int main() {

    Date *date1 = createDate(2021, 04, 29, 19, 30); // 2
    Date *date2 = createDate(2021, 04, 29, 19, 0); // 1
    Date* date3 = createDate(2021, 04, 29, 20, 15); // 3

    Reservation* reservation1 = createReservation("DATE1", date1);
    Reservation* reservation2 = createReservation("DATE2", date2);
    Reservation* reservation3 = createReservation("DATE3", date3);

    BST* tree = createBST(reservation1);
    insert(&tree, reservation2);
    insert(&tree, reservation3);

    // deleteFromBST(tree, reservation1);

    traverse(tree);

    return 0;
}
