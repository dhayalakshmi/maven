#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

int st[MAX_SIZE];
int top = -1;

// Stack operations
void push(int e) {
    if (top < MAX_SIZE - 1) {
        st[++top] = e;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

int pop() {
    if (top >= 0) {
        return st[top--];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

// Function to check if character is operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to evaluate prefix expression
int evaluatePrefix(char* exp) {
    int len = strlen(exp);
    for (int i = len - 1; i >= 0; i--) {
        if (exp[i] == ' ') {
            continue; // Skip spaces
        }
        else if (isdigit(exp[i])) {
            // Handle multi-digit numbers
            int num = 0, power = 1;
            while (i >= 0 && isdigit(exp[i])) {
                num = num + (exp[i] - '0') * power;
                power *= 10;
                i--;
            }
            i++; // Adjust index after number extraction
            push(num);
        }
        else if (isOperator(exp[i])) {
            int op1 = pop();
            int op2 = pop();
            switch (exp[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': 
                    if (op2 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    push(op1 / op2); 
                    break;
                default: 
                    printf("Invalid operator: %c\n", exp[i]);
                    exit(1);
            }
        }
        else {
            printf("Invalid character in expression: %c\n", exp[i]);
            exit(1);
        }
    }
    return pop();
}

// Function to test evaluation with multiple expressions
void testExpressions() {
    // Test cases array
    struct TestCase {
        char* expression;
        int expected;
    } testCases[] = {
        {"+ 5 * 3 2", 11},      // 5 + (3 * 2)
        {"* + 1 2 3", 9},        // (1 + 2) * 3
        {"- / 10 2 1", 4},       // (10 / 2) - 1
        {"+ * 3 4 5", 17},       // (3 * 4) + 5
        {"+ 100 200", 300},      // Simple addition
        {"/ * + 5 3 2 4", 4},    // ((5 + 3) * 2) / 4
        {"- * 5 6 + 7 8", 15}    // (5 * 6) - (7 + 8)
    };

    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    int passed = 0;

    printf("Running test cases...\n\n");
    for (int i = 0; i < numTests; i++) {
        printf("Test %d: %s\n", i+1, testCases[i].expression);
        printf("Expected: %d\n", testCases[i].expected);
        
        int result = evaluatePrefix(testCases[i].expression);
        printf("Result: %d - ", result);
        
        if (result == testCases[i].expected) {
            printf("PASSED\n\n");
            passed++;
        } else {
            printf("FAILED\n\n");
        }
    }

    printf("Test summary: %d/%d passed (%.0f%%)\n", 
           passed, numTests, (float)passed/numTests * 100);
}

int main() {
    printf("Prefix Expression Evaluator\n");
    printf("==========================\n\n");
    
    // Run automated tests
    testExpressions();
    
    // Example of evaluating a single expression
    printf("\nEvaluating sample expression: * + 4 5 6\n");
    printf("Result: %d\n", evaluatePrefix("* + 4 5 6"));  // Should print 54
    
    return 0;
}
