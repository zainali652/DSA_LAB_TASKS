#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node {
    string orderID;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Push a new order
    void push(string id) {
        Node* newNode = new Node;

        newNode->orderID = id;
        newNode->next = top;

        top = newNode;
    }

    // Display all orders from top to bottom
    void display() {
        if (top == nullptr) {
            cout << "No orders available." << endl;
            return;
        }

        Node* temp = top;

        while (temp != nullptr) {
            cout << temp->orderID << endl;
            temp = temp->next;
        }
    }

    // Process the latest order
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* temp = top;

        cout << "Processed order: "
             << temp->orderID << endl;

        top = top->next;
        delete temp;
    }

    // Display the current top order
    void displayTop() {
        if (top == nullptr) {
            cout << "No current order." << endl;
        } else {
            cout << "Current TOP order: "
                 << top->orderID << endl;
        }
    }

    // Check whether the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Destructor to free remaining nodes
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack restaurant;

    // Push restaurant order IDs
    restaurant.push("ORD-101");
    restaurant.push("ORD-102");
    restaurant.push("ORD-103");
    restaurant.push("ORD-104");

    cout << "Restaurant orders (TOP to bottom):" << endl;
    restaurant.display();

    // Process two latest orders
    cout << "\nProcessing two orders:" << endl;
    restaurant.pop();
    restaurant.pop();

    // Display the current top order
    restaurant.displayTop();

    // Display remaining orders
    cout << "\nRemaining orders:" << endl;
    restaurant.display();

    // Check whether the stack is empty
    cout << "\nIs the stack empty? ";

    if (restaurant.isEmpty()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}