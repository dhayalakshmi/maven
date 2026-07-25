#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string PrefixToPostfix(string prefix) {
    stack<string> s;

    // Traverse the prefix expression from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            // Pop two operands from stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            // Concatenate in postfix order: operand1 operand2 operator
            string exp = op1 + op2 + prefix[i];

            // Push the resulting expression back to stack
            s.push(exp);
        }
        else {
            // Operand, push to stack as string
            s.push(string(1, prefix[i]));
        }
    }

    // Top of stack contains final postfix expression
    return s.top();
}

int main() {
    string prefix, postfix;
    cout << "Enter a PREFIX Expression: ";
    cin >> prefix;

    postfix = PrefixToPostfix(prefix);

    cout << "POSTFIX Expression: " << postfix << endl;
    return 0;
}
