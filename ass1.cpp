#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Node {
    char data;
    Node *left, *right;
};

Node* constructTree(string expr) {
    stack<Node*> stack;
    for (int i = expr.length() - 1; i >= 0; i--) {
        Node *node = new Node;
        node->data = expr[i];
        node->right = node->left = NULL;

        if (isdigit(expr[i])) {
            stack.push(node);
        } else {
            node->right = stack.top();
            stack.pop();
            node->left = stack.top();
            stack.pop();
            stack.push(node);
        }
    }
    return stack.top();
}

void inorderRecursive(Node *node) {
    if (!node) {
        return;
    }
    inorderRecursive(node->left);
    cout << node->data << " ";
    inorderRecursive(node->right);
}

void inorderNonRecursive(Node *root) {
    stack<Node*> stack;
    Node *node = root;
    while (node || !stack.empty()) {
        while (node) {
            stack.push(node);
            node = node->left;
        }
        node = stack.top();
        stack.pop();
        cout << node->data << " ";
        node = node->right;
    }
}

int main() {
    string expr = "+34*56";
    Node *root = constructTree(expr);
    cout << "Recursive In-Order: ";
    inorderRecursive(root);
    cout << endl << "Non-Recursive In-Order: ";
    inorderNonRecursive(root);
    cout << endl;
    return 0;
}
