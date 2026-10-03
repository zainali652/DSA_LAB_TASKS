#include <iostream>
#include <string>
using namespace std;

// Node for one patient
struct Node
{
    int patientID;
    string patientName;
    int patientAge;

    Node* next;   // Pointer to the next patient
};

// Add a normal patient at the end
void addPatient(Node*& head)
{
    Node* newNode = new Node;

    cout << "Enter Patient ID: ";
    cin >> newNode->patientID;

    cout << "Enter Patient Name: ";
    cin.ignore();
    getline(cin, newNode->patientName);

    cout << "Enter Patient Age: ";
    cin >> newNode->patientAge;

    // New node will be the last node
    newNode->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        // Move to the last node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Connect last node to new patient
        temp->next = newNode;
    }

    cout << "Patient added successfully.\n";
}

// Add emergency patient at the beginning
void addEmergencyPatient(Node*& head)
{
    Node* newNode = new Node;

    cout << "Enter Patient ID: ";
    cin >> newNode->patientID;

    cout << "Enter Patient Name: ";
    cin.ignore();
    getline(cin, newNode->patientName);

    cout << "Enter Patient Age: ";
    cin >> newNode->patientAge;

    // New patient points to current first patient
    newNode->next = head;

    // New patient becomes the first patient
    head = newNode;

    cout << "Emergency patient added at beginning.\n";
}

// Search patient using Patient ID
void searchPatient(Node* head)
{
    int id;

    cout << "Enter Patient ID to search: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->patientID == id)
        {
            cout << "\nPatient Found!\n";
            cout << "ID: " << temp->patientID << endl;
            cout << "Name: " << temp->patientName << endl;
            cout << "Age: " << temp->patientAge << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "Patient not found.\n";
}

// Delete patient using Patient ID
void removePatient(Node*& head)
{
    int id;

    cout << "Enter Patient ID to remove: ";
    cin >> id;

    // If list is empty
    if (head == NULL)
    {
        cout << "Patient not found.\n";
        return;
    }

    // If first patient is the patient we want to delete
    if (head->patientID == id)
    {
        Node* temp = head;
        head = head->next;

        delete temp;

        cout << "Patient removed successfully.\n";
        return;
    }

    Node* temp = head;

    // Find the patient before the required patient
    while (temp->next != NULL)
    {
        if (temp->next->patientID == id)
        {
            Node* deleteNode = temp->next;

            // Skip the patient we want to delete
            temp->next = deleteNode->next;

            delete deleteNode;

            cout << "Patient removed successfully.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Patient not found.\n";
}

// Display all patients
void displayPatients(Node* head)
{
    if (head == NULL)
    {
        cout << "No patients in waiting list.\n";
        return;
    }

    Node* temp = head;

    cout << "\n===== Waiting Patients =====\n";

    while (temp != NULL)
    {
        cout << "Patient ID: " << temp->patientID << endl;
        cout << "Name: " << temp->patientName << endl;
        cout << "Age: " << temp->patientAge << endl;
        cout << "--------------------------\n";

        temp = temp->next;
    }
}

int main()
{
    Node* head = NULL;

    int choice;

    do
    {
        cout << "\n===== Hospital Patient Management =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Emergency Patient\n";
        cout << "3. Search Patient\n";
        cout << "4. Remove Patient\n";
        cout << "5. Display Patients\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addPatient(head);
            break;

        case 2:
            addEmergencyPatient(head);
            break;

        case 3:
            searchPatient(head);
            break;

        case 4:
            removePatient(head);
            break;

        case 5:
            displayPatients(head);
            break;

        case 6:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}