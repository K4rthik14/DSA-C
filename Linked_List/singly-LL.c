#include<stdio.h>
#include<stdlib.h>

//Node structure
struct Node{
    int data;
    struct Node* next;
}

struct Node* head = NULL;

//Function to create a new node
struct Node* createNode (int data)
{

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to insert a node at beginning
void insertBeg(int data)
{
    struct Node* newNode = createNode(data);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}
//Function to insert a node at end
void insertEnd(int data)
{
    struct Node* newNode = createNode(data);
    if(head == NULL)
    {
        head = newNode;
        retturn;

    }
    struct Node* temp = head;
    while(temp->next != NULL)
    {

        temp = temp->next;

    }
    temp->next = newNode;
}


