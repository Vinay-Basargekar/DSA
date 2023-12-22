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
        last = nullptr;
    }

    void create(Node **head, int n)
    {
        Node *temp = *head;
        for (int i = 0; i < n; ++i)
        {
            Node *newNode = new Node;
            cout << "Enter Coefficient: ";
            cin >> newNode->coefficient;
            cout << "Enter Power of x: ";
            cin >> newNode->power_x;
            cout << "Enter Power of y: ";
            cin >> newNode->power_y;

            newNode->next = nullptr;

            if (*head == nullptr)
            {
                *head = newNode;
                newNode->next = newNode;
                temp = newNode;
            }
            else
            {
                newNode->next = temp->next;
                temp->next = newNode;
                temp = newNode;
            }
        }
        last = temp;
    }

    void display()
    {
        if (last == nullptr)
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

    Polynomial addPolynomials(Polynomial &poly2)
    {
        Polynomial result;
        Node *temp1 = last->next, *temp2 = poly2.last->next;

        while (temp1 != last->next && temp2 != poly2.last->next)
        {
            if (temp1->power_x > temp2->power_x)
            {
                result.insertLast(temp1->coefficient, temp1->power_x, temp1->power_y);
                temp1 = temp1->next;
            }
            else if (temp1->power_x < temp2->power_x)
            {
                result.insertLast(temp2->coefficient, temp2->power_x, temp2->power_y);
                temp2 = temp2->next;
            }
            else
            { // temp1->power_x == temp2->power_x
                if (temp1->power_y > temp2->power_y)
                {
                    result.insertLast(temp1->coefficient, temp1->power_x, temp1->power_y);
                    temp1 = temp1->next;
                }
                else if (temp1->power_y < temp2->power_y)
                {
                    result.insertLast(temp2->coefficient, temp2->power_x, temp2->power_y);
                    temp2 = temp2->next;
                }
                else
                { // temp1->power_y == temp2->power_y
                    float sumCoefficients = temp1->coefficient + temp2->coefficient;
                    if (sumCoefficients != 0)
                    {
                        result.insertLast(sumCoefficients, temp1->power_x, temp1->power_y);
                    }
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
            }
        }

        while (temp1 != last->next)
        {
            result.insertLast(temp1->coefficient, temp1->power_x, temp1->power_y);
            temp1 = temp1->next;
        }

        while (temp2 != poly2.last->next)
        {
            result.insertLast(temp2->coefficient, temp2->power_x, temp2->power_y);
            temp2 = temp2->next;
        }

        return result;
    }

    void insertLast(float coef, int p_x, int p_y)
    {
        Node *newNode = new Node;
        newNode->coefficient = coef;
        newNode->power_x = p_x;
        newNode->power_y = p_y;
        newNode->next = nullptr;

        if (last == nullptr)
        {
            last = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }
};

int main()
{
    Polynomial poly1, poly2, result;
    Node *head1 = nullptr;
    Node *head2 = nullptr;
    int numberOfTerms1, numberOfTerms2;

    cout << "Enter the number of terms in the first polynomial: ";
    cin >> numberOfTerms1;
    poly1.create(&head1, numberOfTerms1);

    cout << "Enter the number of terms in the second polynomial: ";
    cin >> numberOfTerms2;
    poly2.create(&head2, numberOfTerms2);

    cout << "Polynomial 1: ";
    poly1.display();
    cout << "Polynomial 2: ";
    poly2.display();

    result = poly1.addPolynomials(poly2);
    cout << "Sum of the polynomials: ";
    result.display();

    return 0;
}
