#include <stdio.h>
#include <stdlib.h>
// Structure for each node in the BST
struct Node {
int data;
struct Node *left, *right;
};
// Function to create a new node
struct Node* createNode(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->left = newNode->right = NULL;
return newNode;
}
// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int value) {
if (root == NULL)
return createNode(value);
if (value < root->data)
root->left = insert(root->left, value);
else if (value > root->data)
root->right = insert(root->right, value);
return root;
}
// Function to find the node with minimum value (used in deletion)
struct Node* findMin(struct Node* node) {
while (node && node->left != NULL)
node = node->left;
return node;
}
// Function to delete a node from BST
struct Node* deleteNode(struct Node* root, int key) {
if (root == NULL)
return root;
// Traverse to find the node
if (key < root->data)root->left = deleteNode(root->left, key);
else if (key > root->data)
root->right = deleteNode(root->right, key);
else {
// Node found: handle cases
// Case 1: No child
if (root->left == NULL && root->right == NULL) {
free(root);
return NULL;
}
// Case 2: One child
else if (root->left == NULL) {
struct Node* temp = root->right;
free(root);
return temp;
}
else if (root->right == NULL) {
struct Node* temp = root->left;
free(root);
return temp;
}
// Case 3: Two children
struct Node* temp = findMin(root->right);
root->data = temp->data;
root->right = deleteNode(root->right, temp->data);
}
return root;
}
// --- Traversal Functions ---
void inorder(struct Node* root) {
if (root != NULL) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}
void preorder(struct Node* root) {
if (root != NULL) {printf("%d ", root->data);
preorder(root->left);
preorder(root->right);
}
}
void postorder(struct Node* root) {
if (root != NULL) {
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}
}
// --- Main Function ---
int main() {
struct Node* root = NULL;
int choice, value;
while (1) {
printf("\n\n--- Binary Search Tree Operations ---\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Inorder Traversal\n");
printf("4. Preorder Traversal\n");
printf("5. Postorder Traversal\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter value to insert: ");
scanf("%d", &value);
root = insert(root, value);
printf("%d inserted successfully.\n", value);
break;
case 2:
printf("Enter value to delete: ");
scanf("%d", &value);
root = deleteNode(root, value);
printf("%d deleted (if present).\n", value);
break;case 3:
printf("Inorder Traversal: ");
inorder(root);
printf("\n");
break;
case 4:
printf("Preorder Traversal: ");
preorder(root);
printf("\n");
break;
case 5:
printf("Postorder Traversal: ");
postorder(root);
printf("\n");
break;
case 6:
printf("Exiting program.\n");
exit(0);
default:
printf("Invalid choice! Try again.\n");
}
}
return 0;
}