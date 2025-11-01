#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// Convert linked list to array
int linkedListToArray(struct Node* head, int arr[]) {
    int i = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    return i; // returns size of array
}

// Bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Main
int main() {
    struct Node* head = NULL;
    int n, val, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        head = insertEnd(head, val);
    }

    int arr[100];
    int size = linkedListToArray(head, arr);

    bubbleSort(arr, size);

    printf("\nSorted Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Enter value to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, size, key);
    if (result != -1)
        printf("Element %d found at position %d\n", key, result + 1);
    else
        printf("Element not found.\n");

    return 0;
}
