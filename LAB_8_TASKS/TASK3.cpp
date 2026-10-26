
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

    // Insert a book ID
    Node* insert(Node* node, int id) {
        if (node == NULL)
            return new Node(id);

        if (id < node->id)
            node->left = insert(node->left, id);
        else if (id > node->id)
            node->right = insert(node->right, id);

        return node;
    }

    // Search for a book and count comparisons
    bool search(int id, int& comparisons) {
        Node* current = root;
        comparisons = 0;

        while (current != NULL) {
            comparisons++;

            if (id == current->id)
                return true;
            else if (id < current->id)
                current = current->left;
            else
                current = current->right;
        }

        return false;
    }
};

int main() {
    BST tree;

    // Insert the given book IDs
    int ids[] = {40, 20, 60, 10, 30, 50, 70};

    for (int i = 0; i < 7; i++)
        tree.root = tree.insert(tree.root, ids[i]);

    int bookID;
    int comparisons = 0;

    cout << "Enter book ID to search: ";
    cin >> bookID;

    // Search for the entered ID
    if (tree.search(bookID, comparisons))
        cout << "Book Found" << endl;
    else
        cout << "Book Not Found" << endl;

    cout << "Number of comparisons: "
         << comparisons << endl;

    return 0;
}
