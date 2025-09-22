 /*Addition and multiplication of polynomials using singly linked lists.*/

 #include <stdio.h>
#include <stdlib.h>

// Structure for a polynomial term
typedef struct Node {
    int coeff;      // coefficient
    int pow;        // power of x
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coeff, int pow) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term in descending order of power
void insertTerm(Node** poly, int coeff, int pow) {
    if (coeff == 0) return;

    Node* newNode = createNode(coeff, pow);

    // If list empty or new power > head power
    if (*poly == NULL || (*poly)->pow < pow) {
        newNode->next = *poly;
        *poly = newNode;
        return;
    }

    Node* curr = *poly;
    Node* prev = NULL;

    while (curr != NULL && curr->pow > pow) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL && curr->pow == pow) {
        curr->coeff += coeff;  // combine like terms
        free(newNode);
        if (curr->coeff == 0) { // remove zero coefficient node
            if (prev) prev->next = curr->next;
            else *poly = curr->next;
            free(curr);
        }
    } else {
        newNode->next = curr;
        if (prev) prev->next = newNode;
    }
}

// Function to display polynomial
void displayPoly(Node* poly) {
    if (!poly) {
        printf("0");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL) printf(" + ");
    }
    printf("\n");
}

// Function for polynomial addition
Node* addPoly(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* p1 = poly1;
    Node* p2 = poly2;

    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return result;
}

// Function for polynomial multiplication
Node* multiplyPoly(Node* poly1, Node* poly2) {
    Node* result = NULL;
    for (Node* p1 = poly1; p1 != NULL; p1 = p1->next) {
        for (Node* p2 = poly2; p2 != NULL; p2 = p2->next) {
            insertTerm(&result, p1->coeff * p2->coeff, p1->pow + p2->pow);
        }
    }
    return result;
}

// Main function
int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    // Example polynomial 1: 3x^3 + 2x^2 + 1
    insertTerm(&poly1, 3, 3);
    insertTerm(&poly1, 2, 2);
    insertTerm(&poly1, 1, 0);

    // Example polynomial 2: 4x^2 + 5x + 6
    insertTerm(&poly2, 4, 2);
    insertTerm(&poly2, 5, 1);
    insertTerm(&poly2, 6, 0);

    printf("Polynomial 1: ");
    displayPoly(poly1);

    printf("Polynomial 2: ");
    displayPoly(poly2);

    Node* sum = addPoly(poly1, poly2);
    printf("Sum: ");
    displayPoly(sum);

    Node* product = multiplyPoly(poly1, poly2);
    printf("Product: ");
    displayPoly(product);

    return 0;
}


