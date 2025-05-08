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
    struct Node *temp;
    struct Node *newNode;

    // Insert first node
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 10;
    newNode->next = newNode; // Point to itself (circular)
    head = newNode;

    // Insert second node
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 20;
    newNode->next = head->next;
    head->next = newNode;

    // Insert third node
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 30;
    newNode->next = head->next;
    head->next = newNode;

    // Traversing the circular linked list
    printf("Circular Linked List: ");
    temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");

    return 0;
}
