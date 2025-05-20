#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

int main() {
    stack[++top] = 10;
    stack[++top] = 20;
    pop();
    pop();
    pop();  // underflow test
    return 0;
}
