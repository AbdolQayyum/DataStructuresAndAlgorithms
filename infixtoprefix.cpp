#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


bool isOperand(char c) {
    return (isalpha(c) || isdigit(c));
}


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// reverse a string
string reverseString(string exp) {
    int n = exp.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
    return exp;
}

// Function to reverse the expression and swap parentheses
string reverseExpression(string exp) {
    exp = reverseString(exp);
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
    }
    return exp;
}

// Function to convert infix to postfix expression
string infixToPostfix(string exp) {
    stack<char> s;
    string postfix;
    
    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        if (isOperand(ch)) {
            postfix += ch;  
        }
        else if (ch == '(') {
            s.push(ch); 
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else if (isOperator(ch)) {
            while (!s.empty() && precedence(ch) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch); 
        }
    }
    
    // Pop remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

// Function to convert infix expression to prefix
string infixToPrefix(string exp) {
    
    string reversedExp = reverseExpression(exp);
    
    
    string postfixExp = infixToPostfix(reversedExp);
    
    string prefixExp = reverseString(postfixExp);
    
    return prefixExp;
}


int main() {
    string infixExpression = "(A + B) * (C - D)";
    cout << "Infix: " << infixExpression << endl;
    string prefixExpression = infixToPrefix(infixExpression);
    cout << "Prefix: " << prefixExpression << endl;
    return 0;
}

