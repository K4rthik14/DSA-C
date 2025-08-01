/*Write a C program to implement a queue using arrays. Include separate functions to:

Insert (enqueue) an element into the queue.

Delete (dequeue) an element from the queue.

Display the elements of the queue.


Handle overflow and underflow conditions appropriately*/
#include <stdio.h>
#define MAX 100
int queue[MAX]; // Array to store queue elements
int front = -1; // Index of the front element
int rear = -1;  // Index of the rear element
// Function to check if the queue is empty
int isEmpty(){
    return (front == -1 && rear == -1);
}

void enqueue(int value){
if (rear ==MAX -1){
    printf("Queue Overfolw\n");
    return;

}
if (front = -1)
front = 0; // If queue is empty, set front to 0

rear++;
queue[rear] =value; // Insert the new element at the rear
printf("Inserted %d into the queue\n", value);
}

void dequeue(){
    if(front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted %d from the queue\n", queue[front]);
    front++;
}

void display(){
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){
    int choice, value;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0; // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}