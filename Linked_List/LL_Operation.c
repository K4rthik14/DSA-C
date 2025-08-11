#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAfter(int prevData, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != prevData) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Previous node not found.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteNode(int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Node not found.\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}
void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void freeList() {
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    head = NULL;
}

int mainMenu() {
    int choice;
    printf("Linked List Operations:\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert After a Node\n");
    printf("4. Delete a Node\n");
    printf("5. Display List\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}


void main(){
    int  val,choice;
    int mainmenu();
    while (1) {
        choice = mainMenu();
        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &val);
                insertAtBeginning(val);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;
            case 3:
                printf("Enter previous node value and new value: ");
                int prevVal;
                scanf("%d %d", &prevVal, &val);
                insertAfter(prevVal, val);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteNode(val);
                break;
            case 5:
                displayList();
                break;
            case 6:
                freeList();
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

}
