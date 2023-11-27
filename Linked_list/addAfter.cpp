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
    void addAfter(int key);
};

void List ::addAfter(int key){
    node *temp,*nn;
    temp = head;
    while(temp != NULL && temp->data != key){
        temp = temp->link;
    }
    if(temp == NULL){
        cout << "Specified node not found"<<endl;
    }
    nn = new node;
    if(nn == NULL){
        cout << "memory full";
        exit(0);
    }
    cout <<endl;
    cout << "Enter data to be added: "; cin >> nn->data;
    nn->link = temp->link;
    temp -> link = nn;
    cout << endl;
    cout << "Node added after!" << endl;
}

int main()
{
    List lst;
    int n;
    cout << "Enter no. of nodes: ";
    cin >> n;
    int key;
    cout << "Enter after which node to be add new node: ";
    cin >> key;
    lst.create(n);
    lst.display();
    lst.addAfter(key);
    lst.display();
}