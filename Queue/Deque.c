#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

// Check if the deque is full
int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

// Check if the deque is empty
int isEmpty() {
    return (front == -1);
}

// Insert at rear
void insertRear(int x) {
    if (isFull()) {
        printf("Overflow! Cannot insert %d at rear.\n", x);
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = x;
    printf("Inserted %d at rear\n", x);
}

// Insert at front
void insertFront(int x) {
    if (isFull()) {
        printf("Overflow! Cannot insert %d at front.\n", x);
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }

    deque[front] = x;
    printf("Inserted %d at front\n", x);
}

// Delete from front
void deleteFront() {
    if (isEmpty()) {
        printf("Underflow! Cannot delete from front.\n");
        return;
    }

    int data = deque[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }

    printf("Deleted %d from front\n", data);
}

// Delete from rear
void deleteRear() {
    if (isEmpty()) {
        printf("Underflow! Cannot delete from rear.\n");
        return;
    }

    int data = deque[rear];
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }

    printf("Deleted %d from rear\n", data);
}

// Display elements of deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}