#include <iostream>
using namespace std;

const int SIZE = 5;

int queue[SIZE];
int front = -1, rear = -1;

// Insert a packet into the circular queue
void enqueue(int packet)
{
    // Queue is full if the next rear position is front
    if ((rear + 1) % SIZE == front)
    {
        cout << "Queue Overflow! Buffer is full.\n";
        return;
    }

    // If queue is empty, initialize front
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;

    queue[rear] = packet;

    cout << "Packet " << packet << " added.\n";
}

// Transmit and remove the oldest packet
void dequeue()
{
    if (front == -1)
    {
        cout << "Queue Underflow! No packets available.\n";
        return;
    }

    cout << "Packet " << queue[front] << " transmitted.\n";

    // If only one packet exists, reset the queue
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

// Display packets from oldest to newest
void display()
{
    if (front == -1)
    {
        cout << "No packets waiting.\n";
        return;
    }

    cout << "Packets waiting: ";

    int i = front;

    while (true)
    {
        cout << queue[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    cout << endl;
}

int main()
{
    int choice, packet;

    do
    {
        cout << "\n--- Network Packet Queue ---\n";
        cout << "1. Add Packet\n";
        cout << "2. Transmit Packet\n";
        cout << "3. Display Packets\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter packet ID: ";
            cin >> packet;
            enqueue(packet);
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
