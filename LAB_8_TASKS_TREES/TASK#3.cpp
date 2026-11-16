#include <iostream>
using namespace std;

// Create Node class
class Node {
public:
    string folder;
    Node* left;
    Node* right;

    Node(string name) {
        folder = name;
        left = NULL;
        right = NULL;
    }
};

// In-order Traversal
// Left -> Root -> Right
void InOrder(Node* root) {

    if (root == NULL) {
        return;
    }

    InOrder(root->left);

    cout << root->folder << " ";

    InOrder(root->right);
}

// Pre-order Traversal
// Root -> Left -> Right
void PreOrder(Node* root) {

    if (root == NULL) {
        return;
    }

    cout << root->folder << " ";

    PreOrder(root->left);

    PreOrder(root->right);
}

// Post-order Traversal
// Left -> Right -> Root
void PostOrder(Node* root) {

    if (root == NULL) {
        return;
    }

    PostOrder(root->left);

    PostOrder(root->right);

    cout << root->folder << " ";
}

int main() {

    // Create binary tree
    Node* root = new Node("C_Drive");

    root->left = new Node("Documents");
    root->right = new Node("Pictures");

    root->left->left = new Node("Assignments");
    root->left->right = new Node("Projects");

    root->right->left = new Node("Photos");
    root->right->right = new Node("Videos");

    // Display all DFS traversals
    cout << "Computer File Explorer\n\n";

    cout << "In-order Traversal: ";
    InOrder(root);

    cout << "\nPre-order Traversal: ";
    PreOrder(root);

    cout << "\nPost-order Traversal: ";
    PostOrder(root);

    return 0;
}
