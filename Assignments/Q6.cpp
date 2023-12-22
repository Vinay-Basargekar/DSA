#include <iostream>
using namespace std;

struct Node
{
    float coefficient;
    int power_x;
    int power_y;
    Node *next;
};

class Polynomial
{
    Node *last;

public:
    Polynomial()
    {
        last = NULL;
    }

    void create()
    {
        int n;
        cout << "Enter the number of terms in the polynomial: ";
        cin >> n;

        Node *temp = last;
        for (int i = 0; i < n; ++i)
        {
            Node *nn = new Node;
            cout << "Enter Coefficient: ";
            cin >> nn->coefficient;
            cout << "Enter Power of x: ";
            cin >> nn->power_x;
            cout << "Enter Power of y: ";
            cin >> nn->power_y;

            nn->next = NULL;

            if (last == NULL)
            {
                last = nn;
                nn->next = nn;
                temp = nn;
            }
            else
            {
                nn->next = temp->next;
                temp->next = nn;
                temp = nn;
            }
        }
        last = temp;
    }

    void display()
    {
        if (last == NULL)
        {
            cout << "The circular linked list is empty." << endl;
            return;
        }

        Node *temp = last->next;
        cout << "The polynomial represented by the circular linked list: ";

        do
        {
            cout << temp->coefficient << "x^" << temp->power_x << "y^" << temp->power_y;
            temp = temp->next;

            if (temp != last->next)
            {
                cout << " + ";
            }
        } while (temp != last->next);
        cout << endl;
    }
};

int main()
{
    Polynomial poly1, poly2, result;
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1) Create polynomial\n";
        cout << "2) Display a polynomial\n";
        cout << "3) Add two polynomials\n";
        cout << "4) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Creating polynomial 1:\n";
            poly1.create();
            break;
        case 2:
            cout << "Displaying polynomial 1:\n";
            poly1.display();
            break;
        case 3:
            break;
        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}