#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node{value, top};
        top = newNode;
    }

    int pop() {
        if (!top) return -1;
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
};

int evaluatePostfix(const string& expression) {
    Stack s;
    for (char ch : expression) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int operand2 = s.pop();
            int operand1 = s.pop();
            int result = 0;
            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }
            s.push(result);
        }
    }
    return s.pop();
}

int main() {
    string postfixExpression;
    cin >> postfixExpression;
    cout << evaluatePostfix(postfixExpression) << endl;
    return 0;
}

