#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() { top = nullptr; }
    void push(char value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    char pop() {
        if (!top) return '\0';
        char value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    char peek() { return top ? top->data : '\0'; }
    bool isEmpty() { return top == nullptr; }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

string infixToPostfix(const char* infix) {
    Stack s;
    string postfix = "";
    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];
        if (isalnum(ch)) postfix += ch;
        else if (ch == '(') s.push(ch);
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') postfix += s.pop();
            s.pop();
        } else if (isOperator(ch)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) postfix += s.pop();
            s.push(ch);
        }
    }
    while (!s.isEmpty()) postfix += s.pop();
    return postfix;
}

int main() {
    char infix[100];
    cin >> infix;
    cout << infixToPostfix(infix) << endl;
    return 0;
}
