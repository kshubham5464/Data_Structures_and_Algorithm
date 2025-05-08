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
    struct Node *newNode, *temp;

    // Insert first node
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 10;
    newNode->next = newNode; // Points to itself
    head = newNode;

    // Insert second node at end
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 20;
    newNode->next = head;

    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    // Insert third node at end
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 30;
    newNode->next = head;

    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    // Traverse the circular linked list
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
