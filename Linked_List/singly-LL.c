#include<stdio.h>
#include<stdlib.h>

//Node structure
struct Node{
    int data;
    struct Node* next;
}

struct Node* head = NULL;

//Function to create a new node
struct Node* createNode (int data)
{

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to insert a node at beginning
void insertBeg(int data)
{
    struct Node* newNode = createNode(data);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}
//Function to insert a node at end
void insertEnd(int data)
{
    struct Node* newNode = createNode(data);
    if(head == NULL)
    {
         head = newNode;
         retturn;

    }
    struct Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
//To inert a node at a given position
void insertAtPos(int data, int pos)
{
    struct Node* newNode = createNode(data);
    if(pos<1)
    {
        printf("Invalid Position\n");
        return;
    }
    if(pos == 1)
    {
    insertBeg(data);
    return;
    }
    
    struct Node* temp = head;
    for(int i=1; i<pos-1; i++)
    
        temp = temp->next;
    
        if(temp == NULL)
        {
            printf("Position out of bounds\n");
            return;
        }
        struct Node* newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;

}     

//fuction to delete a node from beginning
void deleteBeg()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// delete a node from end
void deleteEnd()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
//Function to delete a node from a given position
void deleteAtPos(int pos)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(pos<1)
    {
        printf("Invalid Position\n");
        return;
    
}

    if(pos == 1)
    {
        deleteBeg();
        return;
    }
    struct Node* temp = head;
    for(int i=1; i<pos-1; i++)
    {
        temp = temp->next;
        if(temp == NULL)
        {
            printf("Position out of bounds\n");
            return;
        }
    }
    struct Node* delNode = temp->next;
    if(delNode == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }
    temp->next = delNode->next;
    free(delNode);
}

//Function to display the linked list
void display()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//Main fucntion with menu driven program
int main()
{
    int choice, data, pos;
    while(1)
    {
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBeg(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPos(data, pos);
                break;
            case 4:
                deleteBeg();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

}  

