#include <iostream>
using namespace std;

class Node {
public:
    int id;
    Node* left;
    Node* right;

    Node(int value) {
        id = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    // Insert a patient ID
    Node* insert(Node* node, int id) {
        if (node == NULL)
            return new Node(id);

        if (id < node->id)
            node->left = insert(node->left, id);
        else if (id > node->id)
            node->right = insert(node->right, id);

        return node;
    }

    // In-order: Left, Root, Right
    void inOrder(Node* node) {
        if (node == NULL)
            return;

        inOrder(node->left);
        cout << node->id << " ";
        inOrder(node->right);
    }

    // Pre-order: Root, Left, Right
    void preOrder(Node* node) {
        if (node == NULL)
            return;

        cout << node->id << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // Post-order: Left, Right, Root
    void postOrder(Node* node) {
        if (node == NULL)
            return;

        postOrder(node->left);
        postOrder(node->right);
        cout << node->id << " ";
    }
};

int main() {
    BST tree;

    // Insert patient record IDs
    int ids[] = {40, 20, 60, 10, 30, 50, 70};

    for (int i = 0; i < 7; i++)
        tree.root = tree.insert(tree.root, ids[i]);

    // Display all three traversals
    cout << "In-order Traversal: ";
    tree.inOrder(tree.root);

    cout << "\nPre-order Traversal: ";
    tree.preOrder(tree.root);

    cout << "\nPost-order Traversal: ";
    tree.postOrder(tree.root);

    cout << endl;

    return 0;
}
