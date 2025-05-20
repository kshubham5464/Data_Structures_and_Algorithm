#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void pop() {
    if (top == NULL)
        printf("Stack Underflow\n");
    else {
        struct Node* temp = top;
        printf("%d popped from stack\n", top->data);
        top = top->next;
        free(temp);
    }
}

int main() {
    struct Node* newNode1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
    newNode1->data = 60; newNode1->next = newNode2;
    newNode2->data = 70; newNode2->next = NULL;
    top = newNode1;
    pop();
    pop();
    pop();  // underflow test
    return 0;
}
