#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 100

int st[MAX_SIZE];
int top = -1;

void push(int e) {
    if (top < MAX_SIZE - 1) {
        st[++top] = e;
    } else {
        printf("Stack overflow\n");
        return 1;
    }
}

int pop() {
    if (top >= 0) {
        return st[top--];
    } else {
        printf("Stack underflow\n");
        return 1;
    }
}

int evaluatePrefix(char* exp) {
    int len = strlen(exp);
    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }
        else if (exp[i] == ' ') {
            continue; 
        }
        else {
            int op1 = pop();
            int op2 = pop();
            switch (exp[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                default: 
                    printf("Invalid operator: %c\n", exp[i]);
                    return 1;
            }
        }
    }
    return pop();
}

int main() {
    // Predefined prefix expressions
    char* expressions[] = {
        "+ 5 * 3 2",    // 5 + (3 * 2) = 11
        "* + 1 2 3",    // (1 + 2) * 3 = 9
        "- / 10 2 1",   // (10 / 2) - 1 = 4
        "+ * 3 4 5"     // (3 * 4) + 5 = 17
    };
    
    int num_expressions = sizeof(expressions) / sizeof(expressions[0]);
    
    for (int i = 0; i < num_expressions; i++) {
        printf("Evaluating: %s\n", expressions[i]);
        int result = evaluatePrefix(expressions[i]);
        printf("Result = %d\n\n", result);
    }
    
    return 0;
}
