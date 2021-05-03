#include "BST.h"
#include "../Utility/Utility.h"

BST *createBST(Reservation* reservation) {
    BST *tree = (struct BST *) malloc(sizeof(BST));

    if (!tree) {
        printf("Failed to allocate memory for BST");
        return NULL;
    }

    tree->reservation = reservation;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

BST *minValueBST(BST *tree) {
    BST *curret = tree;

    while (curret && curret->left != NULL)
        curret = curret->left;

    return curret;
}

Reservation *findMax(BST *tree) {
    if (tree->right)
        findMax(tree->right);

    return tree->reservation;
}

void insert(BST **tree, Reservation *reservation) {
    if(reservation == NULL)
        return;

    if ((*tree) == NULL) {
        *tree = createBST(reservation);
    } else {

        Reservation *maxReservation = findMax(*tree);

        int sum1 = convertToMinutes(maxReservation->scheduleDate);
        int sum2 = convertToMinutes(reservation->scheduleDate);

        if (abs(sum1 - sum2) < reservation->timespan) {
            printf("Failed to add reservation to BST because reservations are overlapping!\n");
            return;
        }

        if (isBigger((*tree)->reservation->scheduleDate, reservation->scheduleDate))
            insert(&((*tree)->left), reservation);
        else
            insert(&((*tree)->right), reservation);
    }
}

BST *deleteFromBST(BST *tree, Reservation *reservation) {
    if (tree == NULL)
        return tree;

    if (isBigger(tree->reservation->scheduleDate, reservation->scheduleDate))
        tree->left = deleteFromBST(tree->left, reservation);

    else if (isBigger(reservation->scheduleDate, tree->reservation->scheduleDate))
        tree->right = deleteFromBST(tree->right, reservation);

    else {

        if (tree->left == NULL) {
            BST *tmp = tree->right;
            free(tree);
            return tmp;
        } else if (tree->right == NULL) {
            BST *tmp = tree->left;
            free(tree);
            return tmp;
        }

        BST *tmp = minValueBST(tree->right);

        tree->reservation = tmp->reservation;

        tree->right = deleteFromBST(tree->right, tmp->reservation);
    }

    return tree;
}

void traverse(BST *tree) {
    if(tree == NULL)
        return;

    if (tree->left)
        traverse(tree->left);

//    printf("%i %i %i %i %i\n ", tree->reservation->scheduleDate->year,
//           tree->reservation->scheduleDate->month,
//           tree->reservation->scheduleDate->day,
//           tree->reservation->scheduleDate->hour,
//           tree->reservation->scheduleDate->minute);

    printf("%s ", tree->reservation->patientID);

    if (tree->right)
        traverse(tree->right);
}