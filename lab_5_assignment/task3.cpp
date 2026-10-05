#include <iostream>
#include <string>
using namespace std;

// Node class
class Node {
public:
    string player;
    Node* next;

    // Constructor
    Node(string name) {
        player = name;
        next = NULL;
    }
};

// Circular Linked List class
class Game {
private:
    Node* head;

public:
    // Constructor
    Game() {
        head = NULL;
    }

    // Add a player
    void addPlayer(string name) {
        Node* newNode = new Node(name);

        // If list is empty
        if (head == NULL) {
            head = newNode;

            // First node points to itself
            newNode->next = head;
        }
        else {
            Node* current = head;

            // Find the last node
            while (current->next != head) {
                current = current->next;
            }

            // Last node points to new node
            current->next = newNode;

            // New last node points to head
            newNode->next = head;
        }
    }

    // Display each player's turn once
    void displayTurns() {
        if (head == NULL) {
            return;
        }

        Node* current = head;

        cout << "Player Turns:" << endl;

        do {
            cout << current->player << "'s turn" << endl;
            current = current->next;
        } while (current != head);

        cout << "\nAfter the last player, turn returns to: ";
        cout << head->player << endl;
    }
};

int main() {
    Game game;

    // Add 5 players
    game.addPlayer("Ali");
    game.addPlayer("Ahmed");
    game.addPlayer("Sara");
    game.addPlayer("Hamza");
    game.addPlayer("Ayesha");

    // Display turns
    game.displayTurns();

    return 0;
}
