#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int pow;
    struct Node* next;
} Node;


Node* createNode(int coeff, int pow) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}
Node* insertNode(Node* head, int coeff, int pow) {
    Node* newNode = createNode(coeff, pow);
    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// Function to display polynomial
void display(Node* poly) {
    if (!poly) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL && poly->coeff >= 0)
            printf(" + ");
    }
    printf("\n");
}

// Polynomial Addition
Node* addPoly(Node* poly1, Node* poly2) {
    Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow == poly2->pow) {
            result = insertNode(result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->pow > poly2->pow) {
            result = insertNode(result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else {
            result = insertNode(result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        result = insertNode(result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        result = insertNode(result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }
    return result;
}

// Polynomial Multiplication
Node* multiplyPoly(Node* poly1, Node* poly2) {
    Node* result = NULL;

    for (Node* p1 = poly1; p1 != NULL; p1 = p1->next) {
        for (Node* p2 = poly2; p2 != NULL; p2 = p2->next) {
            int coeff = p1->coeff * p2->coeff;
            int pow = p1->pow + p2->pow;

            // Insert or add to existing power term
            Node* temp = result;
            Node* prev = NULL;
            int found = 0;
            while (temp != NULL) {
                if (temp->pow == pow) {
                    temp->coeff += coeff;
                    found = 1;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
            if (!found) {
                Node* newNode = createNode(coeff, pow);
                if (prev == NULL) {
                    newNode->next = result;
                    result = newNode;
                } else {
                    newNode->next = prev->next;
                    prev->next = newNode;
                }
            }
        }
    }
    return result;
}

/ Function to read polynomial from user
Node* readPoly() {
    Node* poly = NULL;
    int n, coeff, pow;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Enter each term as: coefficient power\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &pow);
        poly = insertNode(poly, coeff, pow);
    }
    return poly;
}

// Main program
int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* sum = NULL;
    Node* product = NULL;

    printf("Enter first polynomial:\n");
    poly1 = readPoly();

    printf("Enter second polynomial:\n");
    poly2 = readPoly();

    printf("\nPolynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    sum = addPoly(poly1, poly2);
    printf("\nSum: ");
    display(sum);

    product = multiplyPoly(poly1, poly2);
    printf("Product: ");
    display(product);

    return 0;
}


