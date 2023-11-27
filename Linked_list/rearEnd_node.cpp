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
    List()
    {
        head = NULL;
    }
    void create(int n)
    {
        node *nn, *prev;
        for (int i = 0; i < n; i++)
        {
            nn = new node;
            cout << "Enter data: ";
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
        node *temp;
        temp = head;
        cout << "Linked list is: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
    }
    void rearEnd(int n);
};

void List ::rearEnd(int n)
{
    node *nn,*temp;
    nn = new node;
    if(nn==NULL){
        cout << "Memory Full";
        exit(0);
    }
    cout <<endl;
    cout << "Enter data: ";
    cin >> nn->data;
    nn->link = NULL;
    temp = head;
    while(temp->link != NULL){
        temp = temp ->link;
    }
    temp ->link = nn;
    cout << "Node added Successfully!"<<endl;
}

int main()
{
    List lst;
    int n;
    cout << "Enter no. of nodes: ";
    cin >> n;
    lst.create(n);
    lst.display();
    lst.rearEnd(n);
    lst.display();
}