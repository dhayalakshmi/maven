#include <stdio.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int isBalanced(char *expr) {
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            push(expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
            char popped = pop();
            if (!isMatching(popped, expr[i]))
                return 0;
        }
    }
    return (top == -1);
}

int main() {
    char expr[] = "((a+b)*[c/d])";
    if (isBalanced(expr))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}
