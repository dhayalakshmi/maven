#include <stdio.h>
#define MAX 100 

int stack[MAX];
int top = -1; 

// Push Operation
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
        printf("%d pushed to stack\n", x);
    }
}

// Pop Operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        printf("%d popped from stack\n", stack[top]);
        return stack[top--];
    }
}
// Peek Operation
int peek() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return -1;
    } else {
        return stack[top];
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int main() {
    push(10);
    push(20);
    push(30);
    display();
    
    printf("Top element is %d\n", peek());
    pop();
    display();
    
    return 0;
}
