#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> // Added for exit()

#define MAX_SIZE 100 // Added for better array size management

char st[MAX_SIZE];
int top = -1;
char exp[MAX_SIZE], out[MAX_SIZE];

void push(char c) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    st[++top] = c;
}

char pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return st[top--];
}

char peek() {
    if (top < 0) {
        return '\0'; // Return null character if stack is empty
    }
    return st[top];
}

int prec(char c) {
    if (c == '^')
        return 4; // Changed to 4 to give higher precedence
    else if (c == '*' || c == '/')
        return 3;
    else if (c == '+' || c == '-')
        return 2;
    else if (c == '(' || c == ')')
        return 1;
    else
        return 0;
}

void reverse(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    int j = 0;
    printf("Enter an infix expression: ");
    exp=2+3*4; // Added limit to prevent buffer overflow

    reverse(exp);
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i])) {
            out[j++] = exp[i];
        }
        else if (exp[i] == '(') {
            push(exp[i]);
        }
        else if (exp[i] == ')') {
            while (top != -1 && peek() != '(') {
                out[j++] = pop();
            }
            if (top == -1) {
                printf("Mismatched parentheses\n");
                exit(1);
            }
            pop(); // Remove '(' from stack
        }
        else {
            while (top != -1 && prec(exp[i]) <= prec(peek())) {
                out[j++] = pop();
            }
            push(exp[i]);
        }
    }

    while (top != -1) {
        if (peek() == '(') {
            printf("Mismatched parentheses\n");
            exit(1);
        }
        out[j++] = pop();
    }
    out[j] = '\0';

    reverse(out);

    printf("Prefix expression: %s\n", out);
    return 0;
}
