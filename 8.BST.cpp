#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    void insert(int data) {
        root = insertRec(root, data);
    }

    bool search(int data) {
        return searchRec(root, data);
    }

    int depth() {
        return depthRec(root);
    }

    void displayLeafNodes() {
        displayLeafNodesRec(root);
    }

private:
    Node* insertRec(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insertRec(node->left, data);
        } else {
            node->right = insertRec(node->right, data);
        }
        return node;
    }

    bool searchRec(Node* node, int data) {
        if (node == nullptr) return false;
        if (data == node->data) return true;
        return data < node->data ? searchRec(node->left, data) : searchRec(node->right, data);
    }

    int depthRec(Node* node) {
        if (node == nullptr) return 0;
        int leftDepth = depthRec(node->left);
        int rightDepth = depthRec(node->right);
        return max(leftDepth, rightDepth) + 1;
    }

    void displayLeafNodesRec(Node* node) {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) {
            cout << node->data << " ";
        }
        displayLeafNodesRec(node->left);
        displayLeafNodesRec(node->right);
    }
};

int main() {
    BinarySearchTree bst;
    int choice, data;

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Display Depth of Tree\n4. Display Leaf Nodes\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            bst.insert(data);
            cout << data << " inserted.\n";
            break;
        case 2:
            cout << "Enter data to search: ";
            cin >> data;
            cout << (bst.search(data) ? "Found" : "Not found") << " in the tree.\n";
            break;
        case 3:
            cout << "Depth of the tree: " << bst.depth() << "\n";
            break;
        case 4:
            cout << "Leaf nodes: ";
            bst.displayLeafNodes();
            cout << "\n";
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
