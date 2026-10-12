#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    string pages[10];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Push a page into the stack
    void push(string page) {
        if (top == 9) {
            cout << "Stack is full!" << endl;
        } else {
            top++;
            pages[top] = page;
        }
    }

    // Display pages from top to bottom
    void display() {
        if (top == -1) {
            cout << "No browsing history." << endl;
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << pages[i] << endl;
        }
    }

    // Remove the top page
    void pop() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Back button removed: "
                 << pages[top] << endl;
            top--;
        }
    }

    // Display the current top page
    void displayTop() {
        if (top == -1) {
            cout << "No current page." << endl;
        } else {
            cout << "Current TOP page: "
                 << pages[top] << endl;
        }
    }
};

int main() {
    Stack browser;

    // Push visited pages
    browser.push("Google");
    browser.push("YouTube");
    browser.push("Facebook");
    browser.push("GitHub");

    cout << "Browsing history (TOP to bottom):" << endl;
    browser.display();

    // Press Back once
    cout << "\nPerforming POP:" << endl;
    browser.pop();

    // Display current top page
    browser.displayTop();

    // Display remaining history
    cout << "\nRemaining browsing history:" << endl;
    browser.display();

    return 0;
}