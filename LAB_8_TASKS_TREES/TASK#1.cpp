#include <iostream>
using namespace std;

// Create a Node class
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

int main() {

    // Create nodes
    Node* root = new Node("HOD");

    root->left = new Node("Coordinator 1");
    root->right = new Node("Coordinator 2");

    root->left->left = new Node("Faculty 1");
    root->left->right = new Node("Faculty 2");

    root->right->left = new Node("Faculty 3");
    root->right->right = new Node("Faculty 4");

    // Display department hierarchy
    cout << "University Department Hierarchy\n\n";

    cout << "Member: " << root->name << endl;
    cout << "Left Child: " << root->left->name << endl;
    cout << "Right Child: " << root->right->name << endl;

    cout << "\nMember: " << root->left->name << endl;
    cout << "Left Child: " << root->left->left->name << endl;
    cout << "Right Child: " << root->left->right->name << endl;

    cout << "\nMember: " << root->right->name << endl;
    cout << "Left Child: " << root->right->left->name << endl;
    cout << "Right Child: " << root->right->right->name << endl;

    cout << "\nMember: " << root->left->left->name << endl;
    cout << "Left Child: None" << endl;
    cout << "Right Child: None" << endl;

    cout << "\nMember: " << root->left->right->name << endl;
    cout << "Left Child: None" << endl;
    cout << "Right Child: None" << endl;

    cout << "\nMember: " << root->right->left->name << endl;
    cout << "Left Child: None" << endl;
    cout << "Right Child: None" << endl;

    cout << "\nMember: " << root->right->right->name << endl;
    cout << "Left Child: None" << endl;
    cout << "Right Child: None" << endl;

    return 0;
}
