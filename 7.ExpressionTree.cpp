#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

Node* constructPostfixTree(const string& postfix) {
    stack<Node*> st;
    for (char c : postfix) {
        if (isOperator(c)) {
            Node* opNode = new Node(c);
            opNode->right = st.top(); st.pop();
            opNode->left = st.top(); st.pop();
            st.push(opNode);
        } else {
            st.push(new Node(c));
        }
    }
    return st.top();
}

Node* constructPrefixTree(const string& prefix) {
    stack<Node*> st;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isOperator(c)) {
            Node* opNode = new Node(c);
            opNode->left = st.top(); st.pop();
            opNode->right = st.top(); st.pop();
            st.push(opNode);
        } else {
            st.push(new Node(c));
        }
    }
    return st.top();
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    string postfix, prefix;
    
    cout << "Enter postfix expression: ";
    cin >> postfix;
    Node* postfixRoot = constructPostfixTree(postfix);
    cout << "In-order: "; inorder(postfixRoot); cout << endl;
    cout << "Pre-order: "; preorder(postfixRoot); cout << endl;
    cout << "Post-order: "; postorder(postfixRoot); cout << endl;
    
    cout << "\nEnter prefix expression: ";
    cin >> prefix;
    Node* prefixRoot = constructPrefixTree(prefix);
    cout << "In-order: "; inorder(prefixRoot); cout << endl;
    cout << "Pre-order: "; preorder(prefixRoot); cout << endl;
    cout << "Post-order: "; postorder(prefixRoot); cout << endl;

    return 0;
}
