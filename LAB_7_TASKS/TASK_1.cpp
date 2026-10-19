#include <iostream>
using namespace std;

const int SIZE = 5;

int queue[SIZE];
int front = -1, rear = -1;

// Insert a customer into the queue
void enqueue(int token)
{
    // Check if the linear queue is full
    if (rear == SIZE - 1)
    {
        cout << "Queue Overflow! No space available.\n";
        return;
    }

    // If the queue is empty, initialize front
    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = token;

    cout << "Customer " << token << " added.\n";
}

// Serve and remove the first customer
void dequeue()
{
    // Check if the queue is empty
    if (front == -1)
    {
        cout << "Queue Underflow! No customer to serve.\n";
        return;
    }

    cout << "Customer " << queue[front] << " is served.\n";

    // If this was the last customer, reset the queue
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

// Display all waiting customers
void display()
{
    if (front == -1)
    {
        cout << "No customers waiting.\n";
        return;
    }

    cout << "Waiting customers: ";

    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";

    cout << endl;
}

// Display the number of waiting customers
void count()
{
    if (front == -1)
        cout << "Waiting customers: 0\n";
    else
        cout << "Waiting customers: " << rear - front + 1 << endl;
}

int main()
{
    int choice, token;

    do
    {
        cout << "\n--- Bank Customer Queue ---\n";
        cout << "1. Add Customer (Enqueue)\n";
        cout << "2. Serve Customer (Dequeue)\n";
        cout << "3. Display Customers\n";
        cout << "4. Count Waiting Customers\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter customer token: ";
            cin >> token;
            enqueue(token);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            count();
            break;

        case 5:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
