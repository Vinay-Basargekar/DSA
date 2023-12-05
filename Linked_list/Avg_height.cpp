#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};

class List
{
    node *head;

public:
    List() { head = NULL; }

    void create(int n)
    {
        node *nn, *prev;
        for (int i = 0; i < n; i++)
        {
            nn = new node;
            cout << "Enter height for node " << i + 1 << ": ";
            cin >> nn->data;
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

    void display()
    {
        node *temp = head;
        int sum = 0;
        int count = 0;

        while (temp != NULL)
        {
            sum += temp->data;
            count++;
            temp = temp->link;
        }

        if (count > 0)
        {
            double average = (double)sum / count;
            cout << "Average height is: " << average << endl;
        }
        else
        {
            cout << "List is empty" << endl;
        }
    }
};

int main()
{
    List lst;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    lst.create(n);
    lst.display();
    return 0;
}
