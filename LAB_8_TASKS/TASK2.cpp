
#include <iostream>
using namespace std;

// Node class for the BST
class Node {
public:
    int roll;
    Node* left;
    Node* right;

    Node(int r) {
        roll = r;
        left = NULL;
        right = NULL;
    }
};

// Binary Search Tree class
class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    // Insert a roll number
    Node* insert(Node* node, int roll) {
        if (node == NULL)
            return new Node(roll);

        if (roll < node->roll)
            node->left = insert(node->left, roll);
        else if (roll > node->roll)
            node->right = insert(node->right, roll);
        else
            cout << "Duplicate roll number ignored: "
                 << roll << endl;

        return node;
    }

    // Display numbers in ascending order
    void inOrder(Node* node) {
        if (node == NULL)
            return;

        inOrder(node->left);
        cout << node->roll << " ";
        inOrder(node->right);
    }
};

int main() {
    BST tree;

    // Insert the given roll numbers
    int numbers[] = {45, 25, 65, 15, 35, 55, 75};

    for (int i = 0; i < 7; i++)
        tree.root = tree.insert(tree.root, numbers[i]);

    // Take two additional roll numbers
    int roll;

    for (int i = 1; i <= 2; i++) {
        cout << "Enter additional roll number " << i << ": ";
        cin >> roll;
        tree.root = tree.insert(tree.root, roll);
    }

    // Display sorted roll numbers
    cout << "\nRoll numbers in ascending order: ";
    tree.inOrder(tree.root);

    cout << endl;
    return 0;
}
