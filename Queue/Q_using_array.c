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