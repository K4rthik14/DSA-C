#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
// Node structure for adjacency list
struct Node {
int data;
struct Node* next;
};
struct Node* adjList[SIZE]; // Adjacency list
int visited[SIZE];
// Visited array for BFS
// Queue for BFS
int queue[SIZE], front = 0, rear = -1;
// Function to add edge (undirected)
void addEdge(int u, int v) {
struct Node* newNode = malloc(sizeof(struct Node));
newNode->data = v;
newNode->next = adjList[u];
adjList[u] = newNode;
// Undirected graph: add v -> u and u -> v
newNode = malloc(sizeof(struct Node));
newNode->data = u;
newNode->next = adjList[v];
adjList[v] = newNode;
}
// Function to print adjacency list
void printGraph(int vertices) {
for (int i = 0; i < vertices; i++) {
struct Node* temp = adjList[i];
printf("Vertex %d:", i);
while (temp != NULL) {
printf(" -> %d", temp->data);
temp = temp->next;
}
printf("\n");
}
}// Enqueue function
void enqueue(int value) {
queue[++rear] = value;
}
// Dequeue function
int dequeue() {
return queue[front++];
}
// BFS function
void bfs(int start) {
printf("\nBFS traversal starting from vertex %d: ", start);
visited[start] = 1;
enqueue(start);
while (front <= rear) {
int current = dequeue();
printf("%d ", current);
struct Node* temp = adjList[current];
while (temp != NULL) {
int neighbor = temp->data;
if (!visited[neighbor]) {
visited[neighbor] = 1;
enqueue(neighbor);
}
temp = temp->next;
}
}
printf("\n");
}
// Main function
int main() {
int vertices, edges, u, v, start;
printf("Enter number of vertices: ");
scanf("%d", &vertices);
printf("Enter number of edges: ");
scanf("%d", &edges);for (int i = 0; i < edges; i++) {
printf("Enter edge (u v): ");
scanf("%d %d", &u, &v);
addEdge(u, v);
}
printf("\nAdjacency List:\n");
printGraph(vertices);
printf("\nEnter starting vertex for BFS: ");
scanf("%d", &start);
bfs(start);
return 0;
}