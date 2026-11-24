
#include <iostream>
#include <string>
using namespace std;

class Medicine {
public:
    string name;
    int medicineID;
    int expiryDate;
    Medicine *left, *right;

    Medicine(string n, int id, int date) {
        name = n;
        medicineID = id;
        expiryDate = date;
        left = right = NULL;
    }
};

class MinHeap {
    Medicine* heap[100];
    int size;

public:
    MinHeap() {
        size = 0;
    }

    void connectNodes() {
        for (int i = 0; i < size; i++) {
            heap[i]->left = NULL;
            heap[i]->right = NULL;

            if (2 * i + 1 < size)
                heap[i]->left = heap[2 * i + 1];

            if (2 * i + 2 < size)
                heap[i]->right = heap[2 * i + 2];
        }
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[index]->expiryDate <
                heap[parent]->expiryDate) {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void insert(string name, int id, int date) {
        if (size == 100) return;

        heap[size] = new Medicine(name, id, date);

        heapifyUp(size);
        size++;

        connectNodes();
    }

    void heapifyDown(int index) {
        while (true) {
            int smallest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size &&
                heap[left]->expiryDate <
                heap[smallest]->expiryDate)
                smallest = left;

            if (right < size &&
                heap[right]->expiryDate <
                heap[smallest]->expiryDate)
                smallest = right;

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            }
            else {
                break;
            }
        }
    }

    void display() {
        cout << "\nMedicine Heap (Level Order):\n";

        for (int i = 0; i < size; i++) {
            cout << "Name: " << heap[i]->name
                 << ", ID: " << heap[i]->medicineID
                 << ", Expiry Date: "
                 << heap[i]->expiryDate << endl;
        }
    }

    void deleteNearestExpiry() {
        if (size == 0) {
            cout << "No medicines available!\n";
            return;
        }

        cout << "\nMedicine with Nearest Expiry:\n";

        cout << "Name: " << heap[0]->name
             << ", ID: " << heap[0]->medicineID
             << ", Expiry Date: "
             << heap[0]->expiryDate << endl;

        delete heap[0];

        heap[0] = heap[size - 1];
        size--;

        if (size > 0)
            heapifyDown(0);

        connectNodes();
    }

    ~MinHeap() {
        for (int i = 0; i < size; i++)
            delete heap[i];
    }
};

int main() {
    MinHeap h;

    h.insert("Panadol", 301, 20261215);
    h.insert("Brufen", 302, 20261120);
    h.insert("Augmentin", 303, 20270310);
    h.insert("Calpol", 304, 20261005);
    h.insert("Disprin", 305, 20270125);
    h.insert("Flagyl", 306, 20261201);

    h.display();

    h.deleteNearestExpiry();

    cout << "\nUpdated Medicine Heap:";
    h.display();

    return 0;
}
