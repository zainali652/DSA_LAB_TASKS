#include <iostream>
#include <queue>
using namespace std;

// Create Node class
class Node {
public:
    string data;
    Node* left;
    Node* right;

    Node(string value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// BFS Traversal Function
void BFS(Node* root) {

    // Create a queue
    queue<Node*> q;

    // Insert root into queue
    q.push(root);

    while (!q.empty()) {

        // Get front node
        Node* current = q.front();

        // Remove it from queue
        q.pop();

        // Display node data
        cout << current->data << " ";

        // Insert left child
        if (current->left != NULL) {
            q.push(current->left);
        }

        // Insert right child
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

int main() {

    // Create binary tree
    Node* root = new Node("Electronics");

    root->left = new Node("Clothing");
    root->right = new Node("Accessories");

    root->left->left = new Node("Mobiles");
    root->left->right = new Node("Laptops");

    root->right->left = new Node("Men");
    root->right->right = new Node("Women");

    // Display BFS traversal
    cout << "Online Shopping Categories\n";
    cout << "BFS Traversal: ";

    BFS(root);

    return 0;
}
