#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }

float evaluatePostfix(char *exp) {
    for (int i = 0; exp[i]; i++) {
        if (isspace(exp[i])) continue;

        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            int b = pop();
            int a = pop();
            switch (exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[MAX];
    printf("Enter postfix expression: ");
    fgets(exp, MAX, stdin);
    printf("Result: %.2f\n", evaluatePostfix(exp));
    return 0;
}
