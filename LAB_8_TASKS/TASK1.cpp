#include <iostream>
#include <string>
using namespace std;

// Class to create a family tree node
class Node {
public:
    string name;
    Node* left;
    Node* right;

    // Constructor
    Node(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

// Display each person and their children
void displayTree(Node* root) {
    if (root == NULL)
        return;

    cout << "Person: " << root->name << endl;

    if (root->left != NULL)
        cout << "Left Child: " << root->left->name << endl;
    else
        cout << "Left Child: None" << endl;

    if (root->right != NULL)
        cout << "Right Child: " << root->right->name << endl;
    else
        cout << "Right Child: None" << endl;

    cout << "-------------------" << endl;

    // Display the left and right subtrees
    displayTree(root->left);
    displayTree(root->right);
}

int main() {
    // Create seven family members
    Node* root = new Node("Grandfather");
    root->left = new Node("Father");
    root->right = new Node("Uncle");
    root->left->left = new Node("Son");
    root->left->right = new Node("Daughter");
    root->right->left = new Node("Cousin1");
    root->right->right = new Node("Cousin2");

    // Display the family tree
    displayTree(root);

    return 0;
}
