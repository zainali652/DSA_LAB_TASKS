#include <iostream>
#include <string>
using namespace std;


// This class represents one course
class Course
{
public:
    string courseCode;
    string courseName;
    int creditHours;

    // Pointer to next course
    Course* next;

    // Constructor
    Course(string code, string name, int hours)
    {
        courseCode = code;
        courseName = name;
        creditHours = hours;
        next = NULL;
    }
};


// This class manages a course linked list
class CourseList
{
private:
    Course* head;

public:

    // Constructor
    CourseList()
    {
        head = NULL;
    }


    // Add course at the beginning
    void addAtBeginning()
    {
        string code;
        string name;
        int hours;

        cout << "Enter Course Code: ";
        cin >> code;

        cout << "Enter Course Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Credit Hours: ";
        cin >> hours;

        // Create a new course
        Course* newCourse = new Course(code, name, hours);

        // New course points to old first course
        newCourse->next = head;

        // New course becomes first
        head = newCourse;

        cout << "Course added at beginning.\n";
    }


    // Add course at the end
    void addAtEnd()
    {
        string code;
        string name;
        int hours;

        cout << "Enter Course Code: ";
        cin >> code;

        cout << "Enter Course Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Credit Hours: ";
        cin >> hours;

        // Create a new course
        Course* newCourse = new Course(code, name, hours);

        // If list is empty
        if (head == NULL)
        {
            head = newCourse;
        }
        else
        {
            Course* temp = head;

            // Move to last course
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            // Add course at the end
            temp->next = newCourse;
        }

        cout << "Course added at end.\n";
    }


    // Search course using Course Code
    void searchCourse()
    {
        string code;

        cout << "Enter Course Code to search: ";
        cin >> code;

        Course* temp = head;

        while (temp != NULL)
        {
            if (temp->courseCode == code)
            {
                cout << "\nCourse Found!\n";
                cout << "Course Code: " << temp->courseCode << endl;
                cout << "Course Name: " << temp->courseName << endl;
                cout << "Credit Hours: " << temp->creditHours << endl;

                return;
            }

            // Move to next course
            temp = temp->next;
        }

        cout << "Course not found.\n";
    }


    // Delete a course using Course Code
    void deleteCourse()
    {
        string code;

        cout << "Enter Course Code to delete: ";
        cin >> code;

        // If list is empty
        if (head == NULL)
        {
            cout << "Course not found.\n";
            return;
        }

        // If first course needs to be deleted
        if (head->courseCode == code)
        {
            Course* temp = head;

            head = head->next;

            delete temp;

            cout << "Course deleted successfully.\n";
            return;
        }

        Course* temp = head;

        // Find the course
        while (temp->next != NULL)
        {
            if (temp->next->courseCode == code)
            {
                Course* deleteCourse = temp->next;

                // Connect previous course to next course
                temp->next = deleteCourse->next;

                delete deleteCourse;

                cout << "Course deleted successfully.\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Course not found.\n";
    }


    // Display all courses
    void displayCourses()
    {
        if (head == NULL)
        {
            cout << "Course list is empty.\n";
            return;
        }

        Course* temp = head;

        while (temp != NULL)
        {
            cout << "Course Code: " << temp->courseCode << endl;
            cout << "Course Name: " << temp->courseName << endl;
            cout << "Credit Hours: " << temp->creditHours << endl;
            cout << "--------------------------\n";

            temp = temp->next;
        }
    }


    // Count total courses
    void countCourses()
    {
        int count = 0;

        Course* temp = head;

        while (temp != NULL)
        {
            count++;

            temp = temp->next;
        }

        cout << "Total Courses: " << count << endl;
    }


    // Add all courses from another list
    void concatenate(CourseList& secondList)
    {
        // If first list is empty
        if (head == NULL)
        {
            head = secondList.head;
            secondList.head = NULL;

            return;
        }

        Course* temp = head;

        // Move to the last course
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Connect last course of first list
        // to first course of second list
        temp->next = secondList.head;

        // Second list is now part of first list
        secondList.head = NULL;

        cout << "Course lists concatenated successfully.\n";
    }
};


int main()
{
    // Create two separate course lists
    CourseList morningCourses;
    CourseList eveningCourses;

    int choice;

    do
    {
        cout << "\n===== Course Management System =====\n";

        cout << "1. Add Course at Beginning\n";
        cout << "2. Add Course at End\n";
        cout << "3. Search Course\n";
        cout << "4. Delete Course\n";
        cout << "5. Display Morning Courses\n";
        cout << "6. Count Morning Courses\n";
        cout << "7. Add Course to Evening List\n";
        cout << "8. Display Evening Courses\n";
        cout << "9. Concatenate Evening List\n";
        cout << "10. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice)
        {
        case 1:
            morningCourses.addAtBeginning();
            break;

        case 2:
            morningCourses.addAtEnd();
            break;

        case 3:
            morningCourses.searchCourse();
            break;

        case 4:
            morningCourses.deleteCourse();
            break;

        case 5:
            cout << "\n===== Morning Courses =====\n";
            morningCourses.displayCourses();
            break;

        case 6:
            morningCourses.countCourses();
            break;

        case 7:
            eveningCourses.addAtEnd();
            break;

        case 8:
            cout << "\n===== Evening Courses =====\n";
            eveningCourses.displayCourses();
            break;

        case 9:
            morningCourses.concatenate(eveningCourses);
            break;

        case 10:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 10);


    return 0;
}