#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node {
    string patientID;
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

    // Push a patient request
    void push(string id) {
        Node* newNode = new Node;

        newNode->patientID = id;
        newNode->next = top;

        top = newNode;
    }

    // Display requests from top to bottom
    void display() {
        if (top == nullptr) {
            cout << "No patient requests." << endl;
            return;
        }

        Node* temp = top;

        while (temp != nullptr) {
            cout << temp->patientID << endl;
            temp = temp->next;
        }
    }

    // Pop the latest patient request
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* temp = top;

        cout << "Handled patient request: "
             << temp->patientID << endl;

        top = top->next;
        delete temp;
    }

    // Display the current top request
    void displayTop() {
        if (top == nullptr) {
            cout << "No current request." << endl;
        } else {
            cout << "Current TOP request: "
                 << top->patientID << endl;
        }
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
    Stack hospital;

    // Push patient request IDs
    hospital.push("P101");
    hospital.push("P102");
    hospital.push("P103");
    hospital.push("P104");

    cout << "Patient requests (TOP to bottom):" << endl;
    hospital.display();

    // Handle the latest request
    cout << "\nPerforming POP:" << endl;
    hospital.pop();

    // Display the new top request
    hospital.displayTop();

    // Display remaining requests
    cout << "\nRemaining patient requests:" << endl;
    hospital.display();

    return 0;
}