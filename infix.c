#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = c;
}


char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}


char peek() {
    if (top == -1) return '\0';
    return stack[top];
}


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


void infixToPostfix(char* infix, char* postfix) {
    int i = 0, k = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {

            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            if (peek() == '(') pop();
        }
        else if (isOperator(c)) {

            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter a valid parenthesized infix expression: ");
    fgets(infix, MAX, stdin);


    int len = 0;
    while (infix[len] != '\0') len++;
    if (infix[len-1] == '\n') infix[len-1] = '\0';

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
