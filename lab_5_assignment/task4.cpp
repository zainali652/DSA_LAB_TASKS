#include <iostream>
#include <string>
using namespace std;

// Node class
class Node {
public:
    string song;
    Node* next;

    // Constructor
    Node(string name) {
        song = name;
        next = NULL;
    }
};

// Playlist class
class Playlist {
private:
    Node* head;

public:
    // Constructor
    Playlist() {
        head = NULL;
    }

    // Add a song
    void addSong(string name) {
        Node* newNode = new Node(name);

        // If playlist is empty
        if (head == NULL) {
            head = newNode;

            // First node points to itself
            newNode->next = head;
        }
        else {
            Node* current = head;

            // Find last node
            while (current->next != head) {
                current = current->next;
            }

            // Connect last node to new node
            current->next = newNode;

            // New node points back to first node
            newNode->next = head;
        }
    }

    // Display all songs once
    void displaySongs() {
        if (head == NULL) {
            return;
        }

        Node* current = head;

        cout << "Playlist (One Round):" << endl;

        do {
            cout << current->song << endl;
            current = current->next;
        } while (current != head);
    }

    // Play playlist for 2 complete rounds
    void playTwoRounds() {
        if (head == NULL) {
            return;
        }

        Node* current = head;

        cout << "\nPlaying Playlist for 2 Rounds:" << endl;

        // 5 songs x 2 rounds = 10 songs
        for (int i = 1; i <= 10; i++) {
            cout << "Playing: " << current->song << endl;

            // Move to next song
            current = current->next;
        }
    }
};

int main() {
    Playlist playlist;

    // Add 5 songs
    playlist.addSong("Shape of You");
    playlist.addSong("Perfect");
    playlist.addSong("Believer");
    playlist.addSong("Faded");
    playlist.addSong("Let Me Down Slowly");

    // Display songs once
    playlist.displaySongs();

    // Play for 2 complete rounds
    playlist.playTwoRounds();

    return 0;
}
