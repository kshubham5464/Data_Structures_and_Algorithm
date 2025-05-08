#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    // Header node initialization
    struct Node* header = (struct Node*)malloc(sizeof(struct Node));
    header->next = NULL;

    // Inserting some nodes
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    n1->data = 10;
    n1->next = NULL;
    header->next = n1;

    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    n2->data = 20;
    n2->next = header->next;
    header->next = n2;

    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    n3->data = 30;
    n3->next = header->next;
    header->next = n3;

    // Print original list
    printf("Original List: ");
    struct Node* temp = header->next;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Delete a node with value 20
    int valueToDelete = 20;
    struct Node* prev = header;
    struct Node* curr = header->next;
    while (curr != NULL) {
        if (curr->data == valueToDelete) {
            prev->next = curr->next;
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    // Print updated list
    printf("After Deletion: ");
    temp = header->next;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
