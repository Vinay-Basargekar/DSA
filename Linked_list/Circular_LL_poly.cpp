#include <iostream>
using namespace std;

struct node
{
    float coefficient;
    int exponent;
    node *link;
};

class List
{
    node *last; 

public:
    List()
    {
        last = NULL;
    }

    void create(int n)
    {
        node *nn;
        for (int i = 0; i < n; i++)
        {
            nn = new node;
            cout << "Enter Coefficient: ";
            cin >> nn->coefficient;
            cout << "Enter exponent: ";
            cin >> nn->exponent;
            nn->link = NULL;
            if (i == 0)
            {
                last = nn;
                nn->link = nn;
                continue;
            }
            nn->link = last->link;
            last->link = nn;
            last = nn;
        }
    }

    void display()
    {
        if (last == NULL)
        {
            cout << "The circular Linked list is empty.";
            return;
        }

        node *temp = last->link;
        cout << "The circular Linked list representing the polynomial is: ";
        do
        {
            cout << temp->coefficient << "x^" << temp->exponent;
            temp = temp->link;
            if (temp != last->link)
            {
                cout << " + ";
            }
        } while (temp != last->link);
    }
};

int main()
{
    List lst;
    int n;
    cout << "Enter the number of terms in the polynomial: ";
    cin >> n;
    lst.create(n);
    lst.display();

    return 0;
}
