#include <iostream>
#include <string>
using namespace std;

// This class represents one order
class Order
{
public:
    string orderID;
    string customerName;
    string foodItem;

    // Pointer to the next order
    Order* next;

    // Constructor
    Order(string id, string name, string food)
    {
        orderID = id;
        customerName = name;
        foodItem = food;
        next = NULL;
    }
};


// This class manages the whole linked list
class FoodDelivery
{
private:
    Order* head;

public:

    // Constructor
    FoodDelivery()
    {
        head = NULL;
    }


    // Add a normal order at the end
    void addOrder()
    {
        string id;
        string name;
        string food;

        cout << "Enter Order ID: ";
        cin >> id;

        cout << "Enter Customer Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Food Item: ";
        getline(cin, food);

        // Create a new order
        Order* newOrder = new Order(id, name, food);

        // If there are no orders
        if (head == NULL)
        {
            head = newOrder;
        }
        else
        {
            Order* temp = head;

            // Move to the last order
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            // Add new order at the end
            temp->next = newOrder;
        }

        cout << "Order added successfully.\n";
    }


    // Add an urgent order at the beginning
    void addUrgentOrder()
    {
        string id;
        string name;
        string food;

        cout << "Enter Urgent Order ID: ";
        cin >> id;

        cout << "Enter Customer Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Food Item: ";
        getline(cin, food);

        // Create new order
        Order* newOrder = new Order(id, name, food);

        // New order points to current first order
        newOrder->next = head;

        // New order becomes the first order
        head = newOrder;

        cout << "Urgent order added at beginning.\n";
    }


    // Search an order using Order ID
    void searchOrder()
    {
        string id;

        cout << "Enter Order ID to search: ";
        cin >> id;

        Order* temp = head;

        while (temp != NULL)
        {
            if (temp->orderID == id)
            {
                cout << "\nOrder Found!\n";
                cout << "Order ID: " << temp->orderID << endl;
                cout << "Customer Name: " << temp->customerName << endl;
                cout << "Food Item: " << temp->foodItem << endl;

                return;
            }

            // Move to next order
            temp = temp->next;
        }

        cout << "Order not found.\n";
    }


    // Remove an order after it is delivered
    void removeOrder()
    {
        string id;

        cout << "Enter Order ID to remove: ";
        cin >> id;

        // Check if list is empty
        if (head == NULL)
        {
            cout << "Order not found.\n";
            return;
        }

        // If the first order is the one to remove
        if (head->orderID == id)
        {
            Order* temp = head;

            head = head->next;

            delete temp;

            cout << "Order delivered and removed.\n";
            return;
        }

        Order* temp = head;

        // Find the order
        while (temp->next != NULL)
        {
            if (temp->next->orderID == id)
            {
                Order* deleteOrder = temp->next;

                // Connect previous order to next order
                temp->next = deleteOrder->next;

                delete deleteOrder;

                cout << "Order delivered and removed.\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Order not found.\n";
    }


    // Display all pending orders
    void displayOrders()
    {
        if (head == NULL)
        {
            cout << "No pending orders.\n";
            return;
        }

        Order* temp = head;

        cout << "\n===== Pending Orders =====\n";

        while (temp != NULL)
        {
            cout << "Order ID: " << temp->orderID << endl;
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Food Item: " << temp->foodItem << endl;
            cout << "--------------------------\n";

            temp = temp->next;
        }
    }
};


int main()
{
    // Create food delivery object
    FoodDelivery system;

    int choice;

    do
    {
        cout << "\n===== Food Delivery System =====\n";
        cout << "1. Add New Order\n";
        cout << "2. Add Urgent Order\n";
        cout << "3. Search Order\n";
        cout << "4. Remove Delivered Order\n";
        cout << "5. Display Pending Orders\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.addOrder();
            break;

        case 2:
            system.addUrgentOrder();
            break;

        case 3:
            system.searchOrder();
            break;

        case 4:
            system.removeOrder();
            break;

        case 5:
            system.displayOrders();
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