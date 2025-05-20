#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack operations
void push(char ch) {
    if (top < MAX - 1)
        stack[++top] = ch;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

void swapParentheses(char *expr) {
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(')
            expr[i] = ')';
        else if (expr[i] == ')')
            expr[i] = '(';
    }
}

// Converts infix to postfix (used as part of infix-to-prefix)
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isspace(ch)) continue;
        
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (peek() != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        } else if (isOperator(ch)) {
            while (precedence(peek()) > precedence(ch) ||
                  (precedence(peek()) == precedence(ch) && ch != '^')) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

// Main function to convert infix to prefix
void infixToPrefix(char *infix, char *prefix) {
    char revInfix[MAX], revPostfix[MAX];

    strcpy(revInfix, infix);
    reverse(revInfix);
    swapParentheses(revInfix);

    infixToPostfix(revInfix, revPostfix);
    reverse(revPostfix);

    strcpy(prefix, revPostfix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    // Remove trailing newline if present
    size_t len = strlen(infix);
    if (infix[len - 1] == '\n')
        infix[len - 1] = '\0';

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);
    return 0;
}
