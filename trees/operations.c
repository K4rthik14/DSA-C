#include <stdio.h>
#include <stdlib.h>
// Node structure
typedef struct Node {
int data;
struct Node* left;
struct Node* right;
} Node;
// Create a new node
Node* createNode(int data) {
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->data = data;
newNode->left = newNode->right = NULL;
return newNode;
}
// Recursively create the binary tree
Node* createTree() {
int data;
printf("Enter data (-1 for no node): ");
scanf("%d", &data);
if (data == -1)
return NULL;
Node* newNode = createNode(data);
printf("Enter left child of %d:\n", data);
newNode->left = createTree();
printf("Enter right child of %d:\n", data);
newNode->right = createTree();
return newNode;
}
// Traversals
void inorder(Node* root) {
if (root) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}
void preorder(Node* root) {
if (root) {
printf("%d ", root->data);
preorder(root->left);
preorder(root->right);
}
}void postorder(Node* root) {
if (root) {
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}
}
// Main
int main() {
Node* root = NULL;
printf("Create the binary tree:\n");
root = createTree();
printf("\nInorder Traversal: ");
inorder(root);
printf("\nPreorder Traversal: ");
preorder(root);
printf("\nPostorder Traversal: ");
postorder(root);
printf("\n");
return 0;
}