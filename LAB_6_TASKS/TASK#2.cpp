
#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    string actions[10];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Push an action into the stack
    void push(string action) {
        if (top == 9) {
            cout << "Stack is full!" << endl;
        } else {
            top++;
            actions[top] = action;
        }
    }

    // Display all actions from top to bottom
    void display() {
        if (top == -1) {
            cout << "No actions available." << endl;
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << actions[i] << endl;
        }
    }

    // Undo the latest action
    void pop() {
        if (top == -1) {
            cout << "No action to undo!" << endl;
        } else {
            cout << "Undo action: "
                 << actions[top] << endl;
            top--;
        }
    }

    // Display the current top action
    void displayTop() {
        if (top == -1) {
            cout << "No actions remaining." << endl;
        } else {
            cout << "Current TOP action: "
                 << actions[top] << endl;
        }
    }
};

int main() {
    Stack editor;

    // Push text editor actions
    editor.push("Type Hello");
    editor.push("Type World");
    editor.push("Add !");
    editor.push("Delete !");

    cout << "Actions (TOP to bottom):" << endl;
    editor.display();

    // Undo the last two actions
    cout << "\nPerforming two Undo operations:" << endl;
    editor.pop();
    editor.pop();

    // Display the current top action
    editor.displayTop();

    // Display remaining actions
    cout << "\nRemaining actions:" << endl;
    editor.display();

    return 0;
}