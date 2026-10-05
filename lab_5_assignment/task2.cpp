#include <iostream>
#include <string>
using namespace std;

// Node class
class Node {
public:
    string image;
    Node* prev;
    Node* next;

    // Constructor
    Node(string name) {
        image = name;
        prev = NULL;
        next = NULL;
    }
};

// Image Gallery class
class ImageGallery {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    ImageGallery() {
        head = NULL;
        tail = NULL;
    }

    // Add an image
    void addImage(string name) {
        Node* newNode = new Node(name);

        // If list is empty
        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            // Connect new node to the last node
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Display images from first to last
    void displayForward() {
        Node* current = head;

        cout << "Images (First -> Last):" << endl;

        while (current != NULL) {
            cout << current->image << endl;
            current = current->next;
        }
    }

    // Display images from last to first
    void displayBackward() {
        Node* current = tail;

        cout << "\nImages (Last -> First):" << endl;

        while (current != NULL) {
            cout << current->image << endl;
            current = current->prev;
        }
    }
};

int main() {
    ImageGallery gallery;

    // Store 5 images
    gallery.addImage("Nature.jpg");
    gallery.addImage("Family.jpg");
    gallery.addImage("Beach.jpg");
    gallery.addImage("Mountain.jpg");
    gallery.addImage("Sunset.jpg");

    // Display images
    gallery.displayForward();
    gallery.displayBackward();

    return 0;
}
