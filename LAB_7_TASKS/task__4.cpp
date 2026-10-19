
#include <iostream>
using namespace std;

const int SIZE = 5;

int dequeArray[SIZE];
int front = -1, rear = -1;

// Insert a request at the front
void insertFront(int id)
{
    if ((rear + 1) % SIZE == front)
    {
        cout << "Deque Overflow! Deque is full.\n";
        return;
    }

    // If deque is empty, initialize both ends
    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        // Move front one position backward circularly
        front = (front - 1 + SIZE) % SIZE;
    }

    dequeArray[front] = id;

    cout << "Request " << id << " inserted at front.\n";
}

// Insert a request at the rear
void insertRear(int id)
{
    if ((rear + 1) % SIZE == front)
    {
        cout << "Deque Overflow! Deque is full.\n";
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        // Move rear one position forward circularly
        rear = (rear + 1) % SIZE;
    }

    dequeArray[rear] = id;

    cout << "Request " << id << " inserted at rear.\n";
}

// Remove a request from the front
void deleteFront()
{
    if (front == -1)
    {
        cout << "Deque Underflow! Deque is empty.\n";
        return;
    }

    cout << "Removed request: " << dequeArray[front] << endl;

    // Reset if this was the last element
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

// Remove a request from the rear
void deleteRear()
{
    if (front == -1)
    {
        cout << "Deque Underflow! Deque is empty.\n";
        return;
    }

    cout << "Removed request: " << dequeArray[rear] << endl;

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        // Move rear one position backward circularly
        rear = (rear - 1 + SIZE) % SIZE;
    }
}

// Display requests from front to rear
void display()
{
    if (front == -1)
    {
        cout << "Deque is empty.\n";
        return;
    }

    cout << "Requests from front to rear: ";

    int i = front;

    while (true)
    {
        cout << dequeArray[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    cout << endl;
}

int main()
{
    int choice, id;

    do
    {
        cout << "\n--- Train Station Deque ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Remove from Front\n";
        cout << "4. Remove from Rear\n";
        cout << "5. Display Requests\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter request ID: ";
            cin >> id;
            insertFront(id);
            break;

        case 2:
            cout << "Enter request ID: ";
            cin >> id;
            insertRear(id);
            break;

        case 3:
            deleteFront();
            break;

        case 4:
            deleteRear();
            break;

        case 5:
            display();
            break;

        case 6:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
