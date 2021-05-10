#include "BST.h"
#include "../Utility/Utility.h"

/// Allocates a BST in memory
BST *createBST(Reservation *reservation) {
    /// Allocates a temporary tree in memory
    BST *tree = (struct BST *) malloc(sizeof(BST));

    /// Checks whether the memory allocation was successful or not
    if (!tree) {
        printf("Failed to allocate memory for BST");
        return NULL;
    }

    /// Initializes the fields of the structure
    tree->reservation = reservation;
    tree->left = NULL;
    tree->right = NULL;

    /// Returns the tree
    return tree;
}

/// Finds the leftmost node in the tree (iteratively)
BST *minValueBST(BST *tree) {
    /// Current tree
    BST *current = tree;

    /// If current is not NULL and current->left exists
    while (current && current->left != NULL)
        /// Change the current subtree to the left subtree
        current = current->left;

    /// Return the current (leftmost) subtree/node
    return current;
}

/// Finds the rightmost node in the tree (recursively)
Reservation *maxValueBST(BST *tree) {
    /// Go left
    if (tree->right)
        maxValueBST(tree->right);

    /// Return the leftmost Reservation in the BST
    return tree->reservation;
}

/// Inserts a Reservation into the tree
void insert(BST **tree, Reservation *reservation) {
    /// If the given Reservation is NULL, we can't insert it into the BST
    if (reservation == NULL)
        return;

    /// If the given tree is NULL (the root does not exist)
    if ((*tree) == NULL) {
        /// Create the root subtree/node
        *tree = createBST(reservation);
    } else {

        /// Find the maximum (latest) reservation in the BST
        Reservation *maxReservation = maxValueBST(*tree);

        /// Convert both reservation dates to minutes
        int sum1 = convertToMinutes(maxReservation->scheduleDate);
        int sum2 = convertToMinutes(reservation->scheduleDate);


        if (abs(sum1 - sum2) < reservation->timespan) {
            printf("Failed to add reservation to BST because reservations are overlapping!\n");
            return;
        }

        /// Compare them (reservation dates) and insert the reservation accordingly
        if (isBigger((*tree)->reservation->scheduleDate, reservation->scheduleDate))
            insert(&((*tree)->left), reservation);
        else
            insert(&((*tree)->right), reservation);
    }
}

/// Deletes a node (BST subtree) from the BST
BST *deleteFromBST(BST *tree, Reservation *reservation) {
    /// If the tree is empty, or the reservation is NULL
    if (tree == NULL || reservation == NULL)
        /// Do nothing
        return NULL;

    /// If the node's reservation is "bigger" than the reservation given in the parameter
    if (isBigger(tree->reservation->scheduleDate, reservation->scheduleDate))
        /// Delete from the left subtree
        tree->left = deleteFromBST(tree->left, reservation);

    /// Else if the reservation's date is "bigger" than the node's reservation
    else if (isBigger(reservation->scheduleDate, tree->reservation->scheduleDate))
        /// Delete from the right subtree
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

/// Inorder traversal of the tree
void traverse(BST *tree) {
    if (tree == NULL)
        return;

    if (tree->left)
        traverse(tree->left);

    printReservation(tree->reservation);

    if (tree->right)
        traverse(tree->right);
}