/* 6. Create Circular List to represent a polynomial for two variables. Write a menu driven
C++ program to perform following operations on polynomials.
a) Create polynomial
b) Display a polynomial
c) Add two polynomials
d) Evaluate a given polynomial
*/

#include <iostream>
#include <math.h>

using namespace std;

struct node
{
    int coeffx, powerx;
    node *link;
};

class clist
{
    node *head = NULL;

public:
    clist() { head = NULL; }
    void create(int n);
    void display();
    clist addtopoly(clist ob2);
    int Evaluate(int x);
};

// a) Create polynomial
void clist::create(int n)
{
    node *nn, *last = NULL;

    for (int i = 0; i < n; i++)
    {
        nn = new node;
        if (nn == NULL)
        {
            cout << "memory is full";
        }
        cout << "Enter coefficient of x" << endl;
        cin >> nn->coeffx;
        cout << "Enter power of x" << endl;
        cin >> nn->powerx;
        if (head == NULL)
        {
            last = nn;
            head = nn;
        }
        else
        {
            last->link = nn;
            last = nn;
        }
    }

    if (last != NULL)
    {
        last->link = head;
    }
}

// b) Display a polynomial
void clist::display()
{
    node *temp = head;
    do
    {
        cout << temp->coeffx << "x^" << temp->powerx;
        temp = temp->link;
        if (temp != head)
        {
            cout << "+";
        }
    } while (temp != head);
    cout << endl;
}

// c) Add two polynomials

clist clist::addtopoly(clist ob2)

{
    clist result, noresult;
    node *t1 = head;
    node *t2 = ob2.head;

    if (t1 == NULL && t2 == NULL)
    {
        cout << "Both polynomials are empty" << endl;
        return noresult;
    }
    else
    {

        do
        {

            if (t1->powerx == t2->powerx)
            {
                node *nn = new node;
                int sumofcoeff = t1->coeffx + t2->coeffx;
                nn->coeffx = sumofcoeff;
                nn->powerx = t1->powerx;
                nn->link = NULL;

                if (result.head == NULL)
                {
                    result.head = nn;
                    nn->link = result.head;
                }
                else
                {
                    node *temp = result.head;

                    do
                    {
                        temp = temp->link;
                    } while (temp->link != result.head);

                    temp->link = nn;
                    nn->link = result.head;
                }

                t1 = t1->link;
                t2 = t2->link;
            }
            else if (t1->powerx > t2->powerx)
            {
                node *nn = new node;
                nn->coeffx = t1->coeffx;
                nn->powerx = t1->powerx;
                nn->link = NULL;

                if (result.head == NULL)
                {
                    result.head = nn;
                    nn->link = result.head;
                }
                else
                {
                    node *temp = result.head;

                    do
                    {
                        temp = temp->link;
                    } while (temp->link != result.head);

                    temp->link = nn;
                    nn->link = result.head;
                }

                t1 = t1->link;
            }
            else
            {
                node *nn = new node;
                nn->coeffx = t2->coeffx;
                nn->powerx = t2->powerx;
                nn->link = NULL;

                if (result.head == NULL)
                {
                    result.head = nn;
                    nn->link = result.head;
                }
                else
                {
                    node *temp = result.head;
                    do
                    {
                        temp = temp->link;
                    } while (temp->link != result.head);

                    temp->link = nn;
                    nn->link = result.head;
                }

                t2 = t2->link;
            }

        } while ((t1 != head || t2 != ob2.head) && t1 != NULL && t2 != NULL);
    }

    while (t1 != head)
    {
        node *nn = new node;
        nn->coeffx = t1->coeffx;
        nn->powerx = t1->powerx;
        nn->link = NULL;

        if (result.head == NULL)
        {
            result.head = nn;
            nn->link = result.head;
        }
        else
        {
            node *temp = result.head;

            do
            {
                temp = temp->link;
            } while (temp->link != result.head);

            temp->link = nn;
            nn->link = result.head;
        }

        t1 = t1->link;
    }

    while (t2 != ob2.head)
    {
        node *nn = new node;
        nn->coeffx = t2->coeffx;
        nn->powerx = t2->powerx;
        nn->link = NULL;

        if (result.head == NULL)
        {
            result.head = nn;
            nn->link = result.head;
        }
        else
        {
            node *temp = result.head;
            do
            {
                temp = temp->link;
            } while (temp->link != result.head);

            temp->link = nn;
            nn->link = result.head;
        }

        t2 = t2->link;
    }

    return result;
}

// d) Evaluate a given polynomial

int clist::Evaluate(int x)
{
    node *temp = head;
    int cal = 0;

    do
    {
        int y = temp->powerx;
        cal = temp->coeffx * pow(x, y) + cal;

        temp = temp->link;
    } while (temp != head);

    return cal;
}

int main()
{
    clist ob1, ob2, result;
    int choice, n, m, x, ans;

    do
    {
        cout << "Menu:\n";
        cout << "1. Create Polynomial 1\n";
        cout << "2. Create Polynomial 2\n";
        cout << "3. Display Polynomial 1\n";
        cout << "4. Display Polynomial 2\n";
        cout << "5. Add Polynomials\n";
        cout << "6. Display Resultant Polynomial\n";
        cout << "7. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number of terms for Polynomial 1: ";
            cin >> n;
            ob1.create(n);
            break;

        case 2:
            cout << "Enter number of terms for Polynomial 2: ";
            cin >> m;
            ob2.create(m);
            break;

        case 3:
            cout << "Polynomial 1: ";
            ob1.display();
            break;

        case 4:
            cout << "Polynomial 2: ";
            ob2.display();
            break;

        case 5:
            result = ob1.addtopoly(ob2);
            result.display();
            cout << "Polynomials added successfully.\n";

            break;

        case 6:
            cout << "Enter X value to Evaluate";
            cin >> x;
            ans = ob1.Evaluate(x);
            cout << "After Evaluate polynomial" << ans << endl;
            break;

        case 7:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
