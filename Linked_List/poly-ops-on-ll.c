#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int coeff;
    int pow;
    struct Node* next;
} Node;

Node *createNode(int coeff, int pow) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}