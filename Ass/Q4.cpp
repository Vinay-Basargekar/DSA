// Create Singly linked list to store details of company , like Name, location and number of employees . Write a menu driven C++ program to perform following operations.
// a) Create a list of N companies
// b) Append a new company to the list
// c) Add a company to the beginning of list
// d) Find no. of Employees, if company name is specified
// e) Find Location if company name is specified
// (Note: Define a C++ class to represent a List and define member functions for the listed operations)

#include <iostream>
#include <string>
using namespace std;

struct Company
{
    string name;
    string location;
    int numEmployees;
};

struct node
{
    Company companyData;
    node *link;
};

class CompanyList
{
private:
    node *head;

public:
    CompanyList() { head = NULL; }

    void create(int n)
    {
        node *prev, *nn;
        for (int i = 0; i < n; i++)
        {
            nn = new node;
            cout << "Enter company name: ";
            cin >> nn->companyData.name;
            cout << "Enter location: ";
            cin >> nn->companyData.location;
            cout << "Enter number of employees: ";
            cin >> nn->companyData.numEmployees;

            nn->link = NULL;
            if (i == 0)
            {
                head = nn;
                prev = nn;
                continue;
            }
            prev->link = nn;
            prev = nn;
        }
    }

    void appendCompany()
    {
        node *nn = new node;
        cout << "Enter company name: ";
        cin >> nn->companyData.name;
        cout << "Enter location: ";
        cin >> nn->companyData.location;
        cout << "Enter number of employees: ";
        cin >> nn->companyData.numEmployees;

        nn->link = NULL;
        if (head == NULL)
        {
            head = nn;
        }
        else
        {
            node *temp = head;
            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = nn;
        }
    }

    void addCompanyToBeginning()
    {
        node *nn = new node;
        cout << "Enter company name: ";
        cin >> nn->companyData.name;
        cout << "Enter location: ";
        cin >> nn->companyData.location;
        cout << "Enter number of employees: ";
        cin >> nn->companyData.numEmployees;

        nn->link = head;
        head = nn;
    }

    int findEmployeesCount(string companyName)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->companyData.name == companyName)
            {
                return temp->companyData.numEmployees;
            }
            temp = temp->link;
        }
        return -1; // If company not found
    }

    string findLocation(string companyName)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->companyData.name == companyName)
            {
                return temp->companyData.location;
            }
            temp = temp->link;
        }
        return "Not Found"; // If company not found
    }

    void display()
    {
        node *temp;
        temp = head;
        cout << "Details of companies in the linked list:\n";
        while (temp != NULL)
        {
            cout << "Company Name: " << temp->companyData.name << endl;
            cout << "Location: " << temp->companyData.location << endl;
            cout << "Number of Employees: " << temp->companyData.numEmployees << endl;
            cout << "-----------------\n";
            temp = temp->link;
        }
    }
};

int main()
{
    CompanyList companyList;
    int choice, n;
    string companyName;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Create list of N companies\n";
        cout << "2. Append a new company\n";
        cout << "3. Add a company to the beginning of the list\n";
        cout << "4. Find number of employees for a specific company\n";
        cout << "5. Find location for a specific company\n";
        cout << "6. Display all companies\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the number of companies: ";
            cin >> n;
            companyList.create(n);
            break;
        case 2:
            companyList.appendCompany();
            break;
        case 3:
            companyList.addCompanyToBeginning();
            break;
        case 4:
            cout << "Enter company name: ";
            cin >> companyName;
            n = companyList.findEmployeesCount(companyName);
            if (n != -1)
            {
                cout << "Number of employees for " << companyName << " is: " << n << endl;
            }
            else
            {
                cout << "Company not found!" << endl;
            }
            break;
        case 5:
            cout << "Enter company name: ";
            cin >> companyName;
            cout << "Location of " << companyName << " is: " << companyList.findLocation(companyName) << endl;
            break;
        case 6:
            companyList.display();
            break;
        case 7:
            cout << "Exiting the program...\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 7);

    return 0;
}
