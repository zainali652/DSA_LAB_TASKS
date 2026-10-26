
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

    // Insert an employee ID
    Node* insert(Node* node, int id) {
        if (node == NULL)
            return new Node(id);

        if (id < node->id)
            node->left = insert(node->left, id);
        else if (id > node->id)
            node->right = insert(node->right, id);

        return node;
    }

    // Find the smallest ID in a subtree
    Node* findMin(Node* node) {
        while (node != NULL && node->left != NULL)
            node = node->left;

        return node;
    }

    // Delete an employee ID
    Node* deleteNode(Node* node, int id) {
        if (node == NULL)
            return NULL;

        if (id < node->id) {
            node->left = deleteNode(node->left, id);
        }
        else if (id > node->id) {
            node->right = deleteNode(node->right, id);
        }
        else {
            // Case 1 and Case 2:
            // Node has no left child
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            // Node has no right child
            if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Node has two children
            Node* temp = findMin(node->right);

            // Copy the smallest value from right subtree
            node->id = temp->id;

            // Delete the copied node
            node->right = deleteNode(node->right, temp->id);
        }

        return node;
    }

    // Display IDs in ascending order
    void inOrder(Node* node) {
        if (node == NULL)
            return;

        inOrder(node->left);
        cout << node->id << " ";
        inOrder(node->right);
    }
};

// Create a fresh tree for each test
void testDeletion(int id, const char* caseName) {
    BST tree;

    int ids[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++)
        tree.root = tree.insert(tree.root, ids[i]);

    cout << "\n" << caseName << endl;
    cout << "Deleting employee ID: " << id << endl;

    tree.root = tree.deleteNode(tree.root, id);

    cout << "Remaining IDs: ";
    tree.inOrder(tree.root);
    cout << endl;
}

int main() {
    // Case 1: Delete a leaf node (20)
    testDeletion(20, "Case 1: Leaf Node");

    // Case 2: Delete a node with one child
    // First delete 20, then 30 has only one child (40)
    BST tree;
    int ids[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++)
        tree.root = tree.insert(tree.root, ids[i]);

    tree.root = tree.deleteNode(tree.root, 20);

    cout << "\nCase 2: One Child Node" << endl;
    cout << "Deleting employee ID: 30" << endl;
    tree.root = tree.deleteNode(tree.root, 30);

    cout << "Remaining IDs: ";
    tree.inOrder(tree.root);
    cout << endl;

    // Case 3: Delete a node with two children (50)
    testDeletion(50, "Case 3: Two Children");

    return 0;
}
