// Create doubly linked list to store details of Doctor , like Name, specialization and phone number . Write a menu driven C++ program to perform following operations.
// a) Create a list by appending a node
// b) List all the Doctors with phone numbers for given specialization.
// c) Reverse the List , such that the last Doctor, should be first in the List.
// (Note: Define a C++ class to represent a List and define member functions for the
// listed operations)

#include <iostream>
#include <string>

using namespace std;

struct node{
    string name;
    string specialization;
    string phoneNumber;
    node *prev;
    node *next;
};

class List{
    node *head;
    node *tail;

public:
    List(){
        head = NULL;
        tail = NULL;
    }

    // Function to append a node to the list
    void appendDoctor(string &name,string &specialization,string &phoneNumber)
    {
        node *nn = new node();
        nn->name = name;
        nn->specialization = specialization;
        nn->phoneNumber = phoneNumber;
        nn->prev = NULL;
        nn->next = NULL;

        if (head == NULL){
            head = tail = nn;
        }
        else
        {
            tail->next = nn;
            nn->prev = tail;
            tail = nn;
        }
        cout << "Doctor details added successfully." << endl;
    }

    // Function to list all doctors with given specialization
    void DocBySpec(string &specialization)
    {
        node *current = head;
        bool found = false;

        cout << "Doctors with specialization '" << specialization << "':" << endl;
        while (current != NULL)
        {
            if (current->specialization == specialization)
            {
                cout << "Name: " << current->name << endl;
                cout << "Phone: " << current->phoneNumber << endl;
                found = true;
            }
            current = current->next;
        }

        if (!found)
        {
            cout << "No doctors found with specialization '" << specialization << endl;
        }
    }

    // Function to reverse the list
    void reverseList()
    {
        if (head == NULL || head == tail)
        {
            cout << "List is empty or has only one element. No change." << endl;
            return;
        }

        node *current = head;
        while (current != NULL)
        {
            node *temp = current->next;
            current->next = current->prev;
            current->prev = temp;

            if (temp == NULL)
            {
                tail = head;
                head = current;
                break;
            }
            current = temp;
        }

        cout << "List reversed successfully." << endl;
    }
    void displayList()
    {
        node *current = head;

        cout << "List of Doctors:" << endl;
        while (current != NULL)
        {
            cout << "Name: " << current->name << ", Specialization: " << current->specialization << ", Phone: " << current->phoneNumber << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    List docList;
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1) Add a Doctor\n";
        cout << "2) List Doctors by Specialization\n";
        cout << "3) Reverse the List\n";
        cout << "4) Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name, specialization, phoneNumber;
            cout << "Enter Doctor's name: ";
            cin >> name;
            cout << "Enter Doctor's specialization: ";
            cin >> specialization;
            cout << "Enter Doctor's phone number: ";
            cin >> phoneNumber;
            docList.appendDoctor(name, specialization, phoneNumber);
            break;
        }
        case 2:
        {
            string specialization;
            cout << "Enter specialization to list Doctors: ";
            cin >> specialization;
            docList.DocBySpec(specialization);
            break;
        }
        case 3:
            docList.reverseList();
            docList.displayList();
            break;
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}
