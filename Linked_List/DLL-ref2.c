#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[100];
    struct Node *prev, *next;
}Node;

Node *current = NULL;  // Pointer to current page

Node *createNode(char *url) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void visitPage(char *url) {
    Node *newNode = createNode(url);

    if (current != NULL && current->next != NULL) {
        Node *temp = current->next;
        while (temp != NULL) {
            Node *next = temp->next;
            free(temp);
            temp = next;
        }
        current->next = NULL;
    }

    if (current != NULL) {
        current->next = newNode;
        newNode->prev = current;
    }

    current = newNode;
    printf("Visited: %s\n", url);
}

void goBack() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Moved Back to: %s\n", current->url);
    } else {
        printf("No previous page.\n");
    }
}

void goForward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Moved Forward to: %s\n", current->url);
    } else {
        printf("No next page.\n");
    }
}

void showCurrent() {
    if (current != NULL)
        printf("Current Page: %s\n", current->url);
    else
        printf("No page opened.\n");
}
void showHistory() {
    if (current == NULL) {
        printf("No history available.\n");
        return;
    }
    Node *temp = current;
    while (temp->prev != NULL) {
        temp = temp->prev;
    }
    printf("Browsing History: ");
    while (temp != NULL) {
        if (temp == current)
            printf("[%s] ", temp->url);
        else
            printf("%s ", temp->url);
        temp = temp->next;
    }
    printf("\n");
}

int main (){
    int choice;
    char url[100];

    while(1){
        printf("\nMenu:\n");
        printf("1. Visit Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Show Current Page\n");
        printf("5. Show History\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from buffer

        switch(choice){
            case 1:
                printf("Enter URL: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = 0;  // Remove newline character
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
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}