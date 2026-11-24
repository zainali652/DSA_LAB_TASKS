
#include <iostream>
#include <string>
using namespace std;

class Order {
public:
    int orderID;
    string customerName;
    float amount;
    Order *left, *right;

    Order(int id, string name, float a) {
        orderID = id;
        customerName = name;
        amount = a;
        left = right = NULL;
    }
};

class MaxHeap {
    Order* heap[100];
    float deletedAmounts[100];
    int size;
    int deletedCount;

public:
    MaxHeap() {
        size = 0;
        deletedCount = 0;
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

            if (heap[index]->amount >
                heap[parent]->amount) {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void insert(int id, string name, float amount) {
        if (size == 100) return;

        heap[size] = new Order(id, name, amount);

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
                heap[left]->amount >
                heap[largest]->amount)
                largest = left;

            if (right < size &&
                heap[right]->amount >
                heap[largest]->amount)
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

    void heapSort() {
        while (size > 0) {
            deletedAmounts[deletedCount] =
                heap[0]->amount;

            deletedCount++;

            delete heap[0];

            heap[0] = heap[size - 1];
            size--;

            if (size > 0)
                heapifyDown(0);

            connectNodes();
        }

        cout << "\nOrder Amounts in Ascending Order:\n";

        for (int i = deletedCount - 1; i >= 0; i--) {
            cout << deletedAmounts[i] << endl;
        }
    }

    ~MaxHeap() {
        for (int i = 0; i < size; i++)
            delete heap[i];
    }
};

int main() {
    MaxHeap h;

    h.insert(1, "Ali", 5000);
    h.insert(2, "Ahmed", 2500);
    h.insert(3, "Zain", 8000);
    h.insert(4, "Usman", 1500);
    h.insert(5, "Hassan", 6000);
    h.insert(6, "Bilal", 3500);

    h.heapSort();

    return 0;
}
