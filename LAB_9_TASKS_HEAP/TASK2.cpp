
#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
    string name;
    int patientID;
    int priority;
    Patient *left, *right;

    Patient(string n, int id, int p) {
        name = n;
        patientID = id;
        priority = p;
        left = right = NULL;
    }
};

class MaxHeap {
    Patient* heap[100];
    int size;

public:
    MaxHeap() {
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

            if (heap[index]->priority >
                heap[parent]->priority) {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void insert(string name, int id, int priority) {
        if (size == 100) return;

        heap[size] = new Patient(name, id, priority);

        heapifyUp(size);
        size++;

        connectNodes();
    }

    void heapifyDown(int index) {
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size &&
                heap[left]->priority >
                heap[largest]->priority)
                largest = left;

            if (right < size &&
                heap[right]->priority >
                heap[largest]->priority)
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else {
                break;
            }
        }
    }

    void display() {
        cout << "\nHospital Patient List:\n";

        for (int i = 0; i < size; i++) {
            cout << "Name: " << heap[i]->name
                 << ", ID: " << heap[i]->patientID
                 << ", Priority: " << heap[i]->priority
                 << endl;
        }
    }

    void treatPatient() {
        if (size == 0) {
            cout << "No patients available!\n";
            return;
        }

        cout << "\nPatient Treated:\n";
        cout << "Name: " << heap[0]->name
             << ", Priority: " << heap[0]->priority
             << endl;

        delete heap[0];

        heap[0] = heap[size - 1];
        size--;

        if (size > 0)
            heapifyDown(0);

        connectNodes();
    }

    void nextPatient() {
        if (size > 0) {
            cout << "\nNext Patient for Treatment:\n";
            cout << "Name: " << heap[0]->name
                 << ", ID: " << heap[0]->patientID
                 << ", Priority: " << heap[0]->priority
                 << endl;
        }
    }

    ~MaxHeap() {
        for (int i = 0; i < size; i++)
            delete heap[i];
    }
};

int main() {
    MaxHeap h;

    h.insert("Ali", 201, 3);
    h.insert("Ahmed", 202, 8);
    h.insert("Zain", 203, 5);
    h.insert("Usman", 204, 10);
    h.insert("Hassan", 205, 6);
    h.insert("Bilal", 206, 9);

    h.display();

    cout << "\nHighest Priority Patient: ";
    h.nextPatient();

    h.treatPatient();

    h.display();

    h.nextPatient();

    return 0;
}
