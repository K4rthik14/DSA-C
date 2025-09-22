#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent each web page
typedef struct Node {
    char url[100];
    struct Node *prev, *next;
} Node;

Node *current = NULL;  // Pointer to current page

// Function to create a new node
Node* createNode(char *url) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to visit a new page
void visitPage(char *url) {
    Node *newNode = createNode(url);

    // If forward history exists, delete it
    if (current != NULL && current->next != NULL) {
        Node *temp = current->next;
        while (temp != NULL) {
            Node *next = temp->next;
            free(temp);
            temp = next;
        }
        current->next = NULL;
    }

    // Attach new node to list
    if (current != NULL) {
        current->next = newNode;
        newNode->prev = current;
    }

    current = newNode;
    printf("Visited: %s\n", url);
}

// Function to move Back
void goBack() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Moved Back to: %s\n", current->url);
    } else {
        printf("No previous page.\n");
    }
}

// Function to move Forward
void goForward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Moved Forward to: %s\n", current->url);
    } else {
        printf("No forward page.\n");
    }
}

// Function to show current page
void showCurrent() {
    if (current != NULL)
        printf("Current Page: %s\n", current->url);
    else
        printf("No page opened.\n");
}

// Function to display entire browsing history up to current page
void showHistory() {
    if (current == NULL) {
        printf("No history available.\n");
        return;
    }
    Node *temp = current;
    // Move to first visited page
    while (temp->prev != NULL) {
        temp = temp->prev;
    }
    printf("Browsing History: ");
    while (temp != NULL) {
        if (temp == current)
            printf("[%s] ", temp->url);  // Mark current page
        else
            printf("%s ", temp->url);
        temp = temp->next;
    }
    printf("\n");
}

// Main function with menu
int main() {
    int choice;
    char url[100];

    while (1) {
        printf("\n--- Browser Menu ---\n");
        printf("1. Visit Page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Show Current Page\n");
        printf("5. Show History\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visitPage(url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                showCurrent();
                break;
            case 5:
                showHistory();
                break;
            case 6:
                printf("Exiting Browser...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

