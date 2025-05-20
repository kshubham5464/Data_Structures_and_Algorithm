#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }

int evaluatePrefix(char *exp) {
    int len = strlen(exp);
    for (int i = len - 1; i >= 0; i--) {
        if (isspace(exp[i])) continue;

        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            int a = pop();
            int b = pop();
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
    printf("Enter prefix expression: ");
    fgets(exp, MAX, stdin);
    printf("Result: %d\n", evaluatePrefix(exp));
    return 0;
}

