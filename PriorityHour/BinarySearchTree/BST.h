#ifndef PRIORITYHOUR_BST_H
#define PRIORITYHOUR_BST_H

#include "../Reservation/Reservation.h"

typedef struct BST {
    Reservation *reservation;
    struct BST *left;
    struct BST *right;
} BST;

BST *createBST(Reservation* reservation);

BST* deleteFromBST(BST* tree, Reservation* reservation);

BST* minValueBST(BST* tree);

Reservation* maxValueBST(BST* tree);

void insert(BST** tree, Reservation *reservation);

void traverse(BST* tree);

#endif //PRIORITYHOUR_BST_H
