#include <iostream>
using namespace std;

struct node
{
    float coefficient;
    int exponent_x;
    int exponent_y;
    node *link;
};

class Polynomial
{
    node *last;

public:
    Polynomial()
    {
        last = NULL;
    }

    void create(int n)
    {
        node *nn;
        for (int i = 0; i < n; ++i)
        {
            nn = new node;
            cout << "Enter Coefficient: ";
            cin >> nn->coefficient;
            cout << "Enter Exponent for x: ";
            cin >> nn->exponent_x;
            cout << "Enter Exponent for y: ";
            cin >> nn->exponent_y;

            nn->link = NULL;

            if (i==0)
            {
                last = nn;
                nn->link = nn;
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
            cout << "The circular linked list is empty." << endl;
            return;
        }

        node *temp = last->link;
        cout << "The polynomial represented by the circular linked list: ";

        do
        {
            cout << temp->coefficient << "x^" << temp->exponent_x << "y^" << temp->exponent_y;
            temp = temp->link;

            if (temp != last->link)
            {
                cout << " + ";
            }
        } while (temp != last->link);

        cout << endl;
    }
};

int main()
{
    Polynomial poly;
    int numberOfTerms;

    cout << "Enter the number of terms in the polynomial: ";
    cin >> numberOfTerms;

    poly.create(numberOfTerms);
    poly.display();

    return 0;
}
