#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char *expr) {
    for (int i = 0; expr[i]; i++) {
        if (isdigit(expr[i])) {
            push(expr[i] - '0');
        }
        else {
            int val2 = pop();
            int val1 = pop();
            switch (expr[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}

int main() {
    char expr[] = "231*+9-";
    printf("Result = %d\n", evaluatePostfix(expr));
    return 0;
}
