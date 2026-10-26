
#include <iostream>
using namespace std;

class Node {
public:
    int id;
    Node* left;
    Node* right;

    // Constructor creates a new product node
    Node(int value) {
        id = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    // Insert a product ID
    Node* insertNode(Node* node, int id) {
        if (node == NULL)
            return new Node(id);

        if (id < node->id)
            node->left = insertNode(node->left, id);
        else if (id > node->id)
            node->right = insertNode(node->right, id);
        else
            cout << "Duplicate product ID not allowed."
                 << endl;

        return node;
    }

    // Search for a product ID
    bool searchNode(Node* node, int id) {
        if (node == NULL)
            return false;

        if (id == node->id)
            return true;
        else if (id < node->id)
            return searchNode(node->left, id);
        else
            return searchNode(node->right, id);
    }

    // Find the smallest ID in a subtree
    Node* findMin(Node* node) {
        while (node != NULL && node->left != NULL)
            node = node->left;

        return node;
    }

    // Delete a product ID
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

            // Node has two children
            Node* temp = findMin(node->right);
            node->id = temp->id;
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

    // Display Root, Left, Right
    void preOrder(Node* node) {
        if (node == NULL)
            return;

        cout << node->id << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // Display Left, Right, Root
    void postOrder(Node* node) {
        if (node == NULL)
            return;

        postOrder(node->left);
        postOrder(node->right);
        cout << node->id << " ";
    }

    // Free all nodes from memory
    void clearTree(Node* node) {
        if (node == NULL)
            return;

        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }

public:
    // Constructor
    BST() {
        root = NULL;
    }

    // Destructor releases dynamically allocated memory
    ~BST() {
        clearTree(root);
        root = NULL;
    }

    // Public function to insert a product
    void insert(int id) {
        root = insertNode(root, id);
    }

    // Public function to search for a product
    void search(int id) {
        if (searchNode(root, id))
            cout << "Product Found." << endl;
        else
            cout << "Product Not Found." << endl;
    }

    // Public function to delete a product
    void remove(int id) {
        if (!searchNode(root, id)) {
            cout << "Product Not Found. Cannot delete."
                 << endl;
            return;
        }

        root = deleteNode(root, id);
        cout << "Product deleted successfully." << endl;
    }

    // Public traversal functions
    void displayInOrder() {
        cout << "In-order: ";
        inOrder(root);
        cout << endl;
    }

    void displayPreOrder() {
        cout << "Pre-order: ";
        preOrder(root);
        cout << endl;
    }

    void displayPostOrder() {
        cout << "Post-order: ";
        postOrder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int choice, id;

    do {
        // Display the menu
        cout << "\n===== ONLINE STORE INVENTORY =====" << endl;
        cout << "1. Insert a product ID" << endl;
        cout << "2. Search for a product ID" << endl;
        cout << "3. Delete a product ID" << endl;
        cout << "4. Display in-order traversal" << endl;
        cout << "5. Display pre-order traversal" << endl;
        cout << "6. Display post-order traversal" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter product ID: ";
                cin >> id;
                tree.insert(id);
                break;

            case 2:
                cout << "Enter product ID to search: ";
                cin >> id;
                tree.search(id);
                break;

            case 3:
                cout << "Enter product ID to delete: ";
                cin >> id;
                tree.remove(id);
                break;

            case 4:
                tree.displayInOrder();
                break;

            case 5:
                tree.displayPreOrder();
                break;

            case 6:
                tree.displayPostOrder();
                break;

            case 7:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 7);

    // The BST destructor runs automatically here
    return 0;
}
