#include <iostream>
using namespace std;

class Node {
public:
    int rollNumber;
    Node* next;

    Node(int roll) {
        rollNumber = roll;
        next = nullptr;
    }
};

class StudentList {
private:
    Node* head;

public:
    StudentList() {
        head = nullptr;
    }

    void addStudent(int roll) {
        Node* newNode = new Node(roll);

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
            cout << temp->rollNumber;
            if (temp->next != nullptr)
                cout << " -> ";
            temp = temp->next;
        }

        cout << endl;
    }

    void searchStudent(int roll) {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->rollNumber == roll) {
                cout << "Student Found" << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Student Not Found" << endl;
    }
};

int main() {
    StudentList students;
    int n, roll, searchRoll;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter Roll Number: ";
        cin >> roll;
        students.addStudent(roll);
    }

    cout << "\nRegistered Students: ";
    students.display();

    cout << "Enter Roll Number to Search: ";
    cin >> searchRoll;

    students.searchStudent(searchRoll);

    return 0;
}