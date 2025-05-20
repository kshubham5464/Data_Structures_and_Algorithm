#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void peek() {
    if (top == NULL)
        printf("Stack is empty\n");
    else
        printf("Top element is %d\n", top->data);
}

int main() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = 80;
    newNode->next = NULL;
    top = newNode;
    peek();
    return 0;
}

