#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Function to create a new stack node
StackNode* createStackNode(int data) {
    StackNode* newNode = (StackNode*) malloc(sizeof(StackNode));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
StackNode* push(StackNode* top, int data) {
    StackNode* newNode = createStackNode(data);
    if (top == NULL) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
    return top;
}

// Function to pop an element from the stack
StackNode* pop(StackNode* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return NULL;
    }
    StackNode* temp = top;
    top = top->next;
    printf("The value being deleted is: %d\n", temp->data);
    free(temp);
    return top;
}

// Function to display the stack elements
void display(StackNode* top) {
    if (top == NULL) {
        printf("The stack is empty\n");
    } else {
        StackNode* temp = top;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to peek at the top element of the stack
int peek(StackNode* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

int main() {
    StackNode* top = NULL;
    int choice, data;
    while (1) {
        printf("------------Stack Operations------------\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &data);
                top = push(top, data);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                printf("The value at the top of the stack is: %d\n", peek(top));
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}