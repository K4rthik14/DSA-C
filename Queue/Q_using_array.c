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
