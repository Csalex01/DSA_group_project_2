#ifndef PRIORITYHOUR_BST_H
#define PRIORITYHOUR_BST_H

#include "../Reservation/Reservation.h"

/// Definition of the Binary Search Tree
typedef struct BST {
    Reservation *reservation;
    struct BST *left;
    struct BST *right;
} BST;

/// Allocates a BST in memory
BST *createBST(Reservation* reservation);

/// Deletes a node (BST subtree) from the BST
BST* deleteFromBST(BST* tree, Reservation* reservation);

/// Finds the leftmost node in the tree (iteratively)
BST* minValueBST(BST* tree);

/// Finds the rightmost node in the tree (recursively)
Reservation* maxValueBST(BST* tree);

/// Inserts a Reservation into the tree
void insert(BST** tree, Reservation *reservation);

/// Inorder traversal of the tree
void traverse(BST* tree);

#endif //PRIORITYHOUR_BST_H
