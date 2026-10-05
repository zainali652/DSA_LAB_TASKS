#include <iostream>
#include <string>
using namespace std;

// Node class
class Node {
public:
    string website;
    Node* prev;
    Node* next;

    // Constructor
    Node(string name) {
        website = name;
        prev = NULL;
        next = NULL;
    }
};

// Doubly Linked List class
class BrowserHistory {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    BrowserHistory() {
        head = NULL;
        tail = NULL;
    }

    // Add a website
    void addWebsite(string name) {
        Node* newNode = new Node(name);

        // If list is empty
        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            // Connect new node with last node
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Display first to last
    void displayForward() {
        Node* current = head;

        cout << "Browser History (First -> Last):" << endl;

        while (current != NULL) {
            cout << current->website << endl;
            current = current->next;
        }
    }

    // Display last to first
    void displayBackward() {
        Node* current = tail;

        cout << "\nBrowser History (Last -> First):" << endl;

        while (current != NULL) {
            cout << current->website << endl;
            current = current->prev;
        }
    }
};

int main() {
    BrowserHistory history;

    // Add 5 websites
    history.addWebsite("Google");
    history.addWebsite("YouTube");
    history.addWebsite("Wikipedia");
    history.addWebsite("GitHub");
    history.addWebsite("StackOverflow");

    // Display in both directions
    history.displayForward();
    history.displayBackward();

    return 0;
}
