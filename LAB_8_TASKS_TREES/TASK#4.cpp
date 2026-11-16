#include <iostream>
using namespace std;

// Create Node class
class Node {
public:
    int data;
    int height;

    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        height = 1;

        left = NULL;
        right = NULL;
    }
};

// Get height of a node
int getHeight(Node* node) {

    if (node == NULL) {
        return 0;
    }

    return node->height;
}

// Calculate balance factor
int getBalance(Node* node) {

    if (node == NULL) {
        return 0;
    }

    return getHeight(node->left) -
           getHeight(node->right);
}

// Right Rotation
Node* rightRotate(Node* y) {

    Node* x = y->left;
    Node* temp = x->right;

    // Perform rotation
    x->right = y;
    y->left = temp;

    // Update heights
    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    return x;
}

// Left Rotation
Node* leftRotate(Node* x) {

    Node* y = x->right;
    Node* temp = y->left;

    // Perform rotation
    y->left = x;
    x->right = temp;

    // Update heights
    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    return y;
}

// Insert a new value into AVL tree
Node* insert(Node* root, int value) {

    // Normal BST insertion
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->data) {

        root->left = insert(root->left, value);

    }
    else if (value > root->data) {

        root->right = insert(root->right, value);

    }
    else {
        return root;
    }

    // Update height
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    // Calculate balance factor
    int balance = getBalance(root);

    // Case 1: LL Rotation
    if (balance > 1 && value < root->left->data) {

        return rightRotate(root);
    }

    // Case 2: RR Rotation
    if (balance < -1 && value > root->right->data) {

        return leftRotate(root);
    }

    // Case 3: LR Rotation
    if (balance > 1 && value > root->left->data) {

        root->left = leftRotate(root->left);

        return rightRotate(root);
    }

    // Case 4: RL Rotation
    if (balance < -1 && value < root->right->data) {

        root->right = rightRotate(root->right);

        return leftRotate(root);
    }

    return root;
}

// In-order Traversal
void inOrder(Node* root) {

    if (root == NULL) {
        return;
    }

    inOrder(root->left);

    cout << root->data << " ";

    inOrder(root->right);
}

// Display tree structure
void displayTree(Node* root, int space = 0) {

    if (root == NULL) {
        return;
    }

    // Increase space for each level
    space += 5;

    // Display right subtree
    displayTree(root->right, space);

    cout << endl;

    for (int i = 5; i < space; i++) {
        cout << " ";
    }

    cout << root->data
         << " (BF=" << getBalance(root) << ")";

    // Display left subtree
    cout << endl;

    displayTree(root->left, space);
}

int main() {

    Node* root = NULL;

    // Appointment token numbers
    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    // Insert all tokens
    for (int i = 0; i < 7; i++) {

        root = insert(root, tokens[i]);
    }

    // Display sorted token numbers
    cout << "Hospital Appointment System\n\n";

    cout << "In-order Traversal: ";

    inOrder(root);

    // Display final AVL tree
    cout << "\n\nFinal Balanced AVL Tree:\n";

    displayTree(root);

    return 0;
}
