// Design and Develop Priority queue using linked representation and
//demonstrate its use.

#include <iostream>
using namespace std;

struct node
{
    int data;
    int Priority;
    node *link;
};

class Priorityqueue
{
    node *front;

public:
    Priorityqueue()
    {
        front = NULL;
    }

    void insert(int data, int Priority);
    void display();
    int delitem();
};

void Priorityqueue::insert(int data, int Priority)
{
    node *nn = new node;
    if (nn == NULL)
    {
        cout << "Memory is full";
        return;
    }

    nn->data = data;
    nn->Priority = Priority;
    nn->link = NULL;

    if (front == NULL || Priority < front->Priority)
    {
        nn->link = front;
        front = nn;
    }
    else
    {
        node *temp = front;

        while (temp->link != NULL && Priority >= temp->link->Priority)
        {
            temp = temp->link;
        }

        nn->link = temp->link;
        temp->link = nn;
    }
}

void Priorityqueue::display()
{
    if (front == NULL)
    {
        cout << "Priority Queue is empty" << endl;
        return;
    }

    node *temp = front;
    cout << "Priority Queue elements:" << endl;

    while (temp != NULL)
    {
        cout << "Data: " << temp->data << " Priority: " << temp->Priority << endl;
        temp = temp->link;
    }
}

int Priorityqueue::delitem()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }

    node *t = front;
    front = t->link;
    int y = t->data;
    delete t;

    return y;
}

int main()
{
    Priorityqueue ob1;
    int data, Priority;
    char ch;

    cout << "Enter 'a' to insert in Queue" << endl;
    cout << "Enter 'b' to display in Queue" << endl;
    cout << "Enter 'c' to delete item in Queue" << endl;
    cout << "Enter 'd' to stop the program execution" << endl;

    do
    {
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 'a':
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter Priority: ";
            cin >> Priority;
            ob1.insert(data, Priority);
            break;

        case 'b':
            ob1.display();
            break;

        case 'c':
            int call;
            call = ob1.delitem();
            if (call != -1)
            {
                cout << "Deleted element: " << call << endl;
            }
            break;

        case 'd':
            cout << "Stopping the program" << endl;
            break;

        default:
            cout << "Enter a valid character" << endl;
        }
    } while (ch != 'd');

    return 0;
}
