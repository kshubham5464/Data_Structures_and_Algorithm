#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void peek() {
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element is %d\n", stack[top]);
}

int main() {
    stack[++top] = 30;
    peek();
    return 0;
}
