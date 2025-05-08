#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* header = (struct Node*)malloc(sizeof(struct Node)); // Header node
    header->next = NULL;

    // Insert first data node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = 10;
    newNode->next = header->next;
    header->next = newNode;

    struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
    newNode2->data = 50;
    newNode2->next = header->next;
    header->next = newNode2;

    // Insert second data node
    struct Node* newNode3 = (struct Node*)malloc(sizeof(struct Node));
    newNode3->data = 20;
    newNode3->next = header->next;
    header->next = newNode3;

    // Display the linked list
    struct Node* temp = header->next;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
