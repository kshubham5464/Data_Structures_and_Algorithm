// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* next;
// };

// // Function to delete the first node
// void deleteAtBeginning(struct Node** headRef) {
//     struct Node* head = *headRef;

//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     // Only one node in the list
//     if (head->next == head) {
//         free(head);
//         *headRef = NULL;
//         return;
//     }

//     // More than one node
//     struct Node* last = head;
//     while (last->next != head) {
//         last = last->next;
//     }

//     struct Node* temp = head;
//     head = head->next;
//     last->next = head;   // Update last node's next
//     free(temp);          // Delete old head

//     *headRef = head;     // Update head reference
// }

// // Function to traverse the circular linked list
// void display(struct Node* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     struct Node* temp = head;
//     printf("Circular Linked List: ");
//     do {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     } while (temp != head);
//     printf("(back to head)\n");
// }

// // Function to insert a node at end (helper for testing)
// void insertEnd(struct Node** headRef, int value) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = value;

//     if (*headRef == NULL) {
//         newNode->next = newNode;
//         *headRef = newNode;
//         return;
//     }

//     struct Node* temp = *headRef;
//     while (temp->next != *headRef) {
//         temp = temp->next;
//     }

//     temp->next = newNode;
//     newNode->next = *headRef;
// }

// int main() {
//     struct Node* head = NULL;

//     // Create circular linked list: 10 -> 20 -> 30 -> (back to head)
//     insertEnd(&head, 10);
//     insertEnd(&head, 20);
//     insertEnd(&head, 30);

//     display(head);  // Before deletion

//     deleteAtBeginning(&head);

//     display(head);  // After deletion

//     return 0;
// }

//--------------------------------without using function------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL;
    struct Node *temp, *newNode;

    // Creating Circular Linked List: 10 -> 20 -> 30 -> (back to head)

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 10;
    newNode->next = newNode; // First node points to itself
    head = newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 20;
    newNode->next = head;
    temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 30;
    newNode->next = head;
    temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;

    //  Deletion at the Beginning

    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else if (head->next == head)
    {
        // Only one node
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }

        temp = head;       // Old head
        head = head->next; // New head
        last->next = head; // Connect last node to new head
        free(temp);        // Delete old head
    }

    // ✅ Display List
    if (head != NULL)
    {
        printf("List after deletion at beginning: ");
        temp = head;
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("(back to head)\n");
    }
    else
    {
        printf("List is now empty.\n");
    }

    return 0;
}
