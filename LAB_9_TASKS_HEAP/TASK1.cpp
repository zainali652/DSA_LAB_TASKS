
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
    int marks;
    Student *left, *right;

    Student(string n, int r, int m) {
        name = n;
        rollNo = r;
        marks = m;
        left = right = NULL;
    }
};

class MaxHeap {
    Student* heap[100];
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

            if (heap[index]->marks > heap[parent]->marks) {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void insert(string name, int roll, int marks) {
        if (size == 100) return;

        heap[size] = new Student(name, roll, marks);

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
                heap[left]->marks > heap[largest]->marks)
                largest = left;

            if (right < size &&
                heap[right]->marks > heap[largest]->marks)
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
        cout << "\nStudent Merit List (Level Order):\n";

        for (int i = 0; i < size; i++) {
            cout << "Name: " << heap[i]->name
                 << ", Roll No: " << heap[i]->rollNo
                 << ", Marks: " << heap[i]->marks << endl;
        }
    }

    void deleteHighest() {
        if (size == 0) {
            cout << "Heap is empty!\n";
            return;
        }

        cout << "\nDeleted Student:\n";
        cout << heap[0]->name << " - "
             << heap[0]->marks << " Marks\n";

        delete heap[0];

        heap[0] = heap[size - 1];
        size--;

        if (size > 0)
            heapifyDown(0);

        connectNodes();
    }

    ~MaxHeap() {
        for (int i = 0; i < size; i++)
            delete heap[i];
    }
};

int main() {
    MaxHeap h;

    h.insert("Ali", 101, 85);
    h.insert("Ahmed", 102, 92);
    h.insert("Zain", 103, 78);
    h.insert("Usman", 104, 95);
    h.insert("Hassan", 105, 88);
    h.insert("Bilal", 106, 81);

    h.display();

    h.deleteHighest();

    cout << "\nUpdated Heap:";
    h.display();

    return 0;
}
