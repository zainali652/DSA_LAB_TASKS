#include <iostream>
#include <string>
using namespace std;

// Node for one student
struct Node
{
    int rollNumber;
    string studentName;
    string attendanceStatus;

    Node* next;
};

// Add a student to the list
void addStudent(Node*& head)
{
    Node* newNode = new Node;

    cout << "Enter Roll Number: ";
    cin >> newNode->rollNumber;

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, newNode->studentName);

    cout << "Enter Attendance Status (Present/Absent): ";
    getline(cin, newNode->attendanceStatus);

    newNode->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        // Go to the last student
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Add new student at the end
        temp->next = newNode;
    }

    cout << "Student added successfully.\n";
}

// Search student using roll number
void searchStudent(Node* head)
{
    int roll;

    cout << "Enter Roll Number to search: ";
    cin >> roll;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->rollNumber == roll)
        {
            cout << "\nStudent Found!\n";
            cout << "Roll Number: " << temp->rollNumber << endl;
            cout << "Name: " << temp->studentName << endl;
            cout << "Attendance: " << temp->attendanceStatus << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "Student not found.\n";
}

// Delete a student
void deleteStudent(Node*& head)
{
    int roll;

    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    // Empty list
    if (head == NULL)
    {
        cout << "Student not found.\n";
        return;
    }

    // If first student needs to be deleted
    if (head->rollNumber == roll)
    {
        Node* temp = head;

        head = head->next;

        delete temp;

        cout << "Student deleted successfully.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->rollNumber == roll)
        {
            Node* deleteNode = temp->next;

            temp->next = deleteNode->next;

            delete deleteNode;

            cout << "Student deleted successfully.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Student not found.\n";
}

// Display all students
void displayStudents(Node* head)
{
    if (head == NULL)
    {
        cout << "Attendance list is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "\n===== Attendance List =====\n";

    while (temp != NULL)
    {
        cout << "Roll Number: " << temp->rollNumber << endl;
        cout << "Name: " << temp->studentName << endl;
        cout << "Attendance: " << temp->attendanceStatus << endl;
        cout << "--------------------------\n";

        temp = temp->next;
    }
}

// Count students who are present
void countPresentStudents(Node* head)
{
    int count = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->attendanceStatus == "Present" ||
            temp->attendanceStatus == "present")
        {
            count++;
        }

        temp = temp->next;
    }

    cout << "Total students present: " << count << endl;
}

// Display final attendance list
void finalAttendanceList(Node* head)
{
    cout << "\n===== Final Attendance List =====\n";

    if (head == NULL)
    {
        cout << "No students in the list.\n";
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->rollNumber << " - "
             << temp->studentName << " - "
             << temp->attendanceStatus << endl;

        temp = temp->next;
    }
}

int main()
{
    Node* head = NULL;

    int choice;

    do
    {
        cout << "\n===== Student Attendance System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Count Present Students\n";
        cout << "6. Final Attendance List\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent(head);
            break;

        case 2:
            searchStudent(head);
            break;

        case 3:
            deleteStudent(head);
            break;

        case 4:
            displayStudents(head);
            break;

        case 5:
            countPresentStudents(head);
            break;

        case 6:
            finalAttendanceList(head);
            break;

        case 7:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}