//Program to implement a basic singly linked list in C
#include <stdio.h>
#include <stdlib.h>
// Structure for a node
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
// Fuction to create a node
struct Node* createNode(int value) {




// insert at beginning