#include <iostream>
using namespace std;

const int SIZE = 5;

struct Patient
{
    int id;
    int priority;
};

Patient queue[SIZE];
int total = 0;

// Add a patient with an assigned priority
void enqueue(int id, int priority)
{
    if (total == SIZE)
    {
        cout << "Queue Overflow! No space for more patients.\n";
        return;
    }

    queue[total].id = id;
    queue[total].priority = priority;
    total++;

    cout << "Patient P" << id << " added.\n";
}

// Treat the patient with the highest priority
void dequeue()
{
    if (total == 0)
    {
        cout << "Queue is empty! No patient to treat.\n";
        return;
    }

    // Find the patient with the smallest priority number
    int highest = 0;

    for (int i = 1; i < total; i++)
    {
        if (queue[i].priority < queue[highest].priority)
            highest = i;
    }

    cout << "Treating patient P" << queue[highest].id
         << " with priority " << queue[highest].priority << endl;

    // Remove the treated patient by shifting later patients left
    for (int i = highest; i < total - 1; i++)
    {
        queue[i] = queue[i + 1];
    }

    total--;
}

// Display all waiting patients
void display()
{
    if (total == 0)
    {
        cout << "No patients waiting.\n";
        return;
    }

    cout << "\nWaiting patients:\n";

    for (int i = 0; i < total; i++)
    {
        cout << "Patient P" << queue[i].id
             << " | Priority: " << queue[i].priority << endl;
    }
}

int main()
{
    int choice, id, priority;

    do
    {
        cout << "\n--- Hospital Priority Queue ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Highest Priority Patient\n";
        cout << "3. Display Patients\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter patient ID (e.g. 102 for P102): ";
            cin >> id;

            cout << "Enter priority (1 = highest): ";
            cin >> priority;

            if (priority < 1)
            {
                cout << "Priority must be 1 or greater.\n";
                break;
            }

            enqueue(id, priority);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
