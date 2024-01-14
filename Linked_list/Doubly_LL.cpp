#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

class List
{
    node *head;
    node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
    void create()
    {
        int n;
        cout << "Enter No. of nodes: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            node *nn;
            nn = new node;
            cout << "Enter data: ";
            cin >> nn->data;
            nn->next = NULL;
            nn->prev = NULL;

            if (head == NULL)
            {
                head = nn;
                tail = nn;
            }
            else
            {
                tail->next = nn;
                nn->prev = tail;
                tail = nn;
            }
        }
    }

    void display()
    {
        node *temp;
        temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    List lst;
    lst.create();
    lst.display();
}