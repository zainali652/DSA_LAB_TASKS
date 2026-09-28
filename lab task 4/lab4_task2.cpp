#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string patientID;
    Node* next;

    Node(string id) {
        patientID = id;
        next = nullptr;
    }
};

class PatientQueue {
private:
    Node* head;

public:
    PatientQueue() {
        head = nullptr;
    }

    void addPatient(string id) {
        Node* newNode = new Node(id);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->patientID;
            if (temp->next != nullptr)
                cout << " -> ";
            temp = temp->next;
        }

        cout << endl;
    }

    void removeFirstPatient() {
        if (head == nullptr) {
            cout << "No patients waiting." << endl;
            return;
        }

        Node* temp = head;
        cout << "Patient " << head->patientID << " is being served." << endl;
        head = head->next;
        delete temp;
    }
};

int main() {
    PatientQueue queue;
    int n;
    string id;

    cout << "Enter number of patients: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter Patient ID: ";
        cin >> id;
        queue.addPatient(id);
    }

    cout << "\nWaiting Patients: ";
    queue.display();

    queue.removeFirstPatient();

    cout << "Updated Queue: ";
    queue.display();

    return 0;
}