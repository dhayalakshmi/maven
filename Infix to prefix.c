#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char op) {
    switch(op) {
        case '^': return 4;
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 2;
        default: return 0;
    }
}

void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

void infixToPrefix(char* infix, char* prefix) {
    reverseString(infix);
    for (int i = 0; infix[i]; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    int j = 0;
    for (int i = 0; infix[i]; i++) {
        if (infix[i] == ' ') continue;
        
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                prefix[j++] = pop();
            }
            pop();
        }
        else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) > precedence(infix[i])) {
                prefix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    while (top != -1) {
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
    reverseString(prefix);
}

int main() {
    char infix[] = "A+B*C-D/E"; 
    char prefix[50];
    
    printf("Infix Expression: %s\n", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix Expression: %s\n", prefix);
    
    return 0;
}
