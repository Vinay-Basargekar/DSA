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
    void addBefore(int key);
};

void List::addBefore(int key){
    node *temp = head;
    node *prev = NULL;

    // Search for the specified node key and keep track of the previous node
    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->link;
    }

    // If the specified node is not found
    if (temp == NULL){
        cout << "Specified node not found" << endl;
        exit(0); 
    }
    node *nn = new node;
    if (nn == NULL){
        cout << "Memory full" << endl;
        exit(0);
    }
    cout << endl;
    cout << "Enter data to be added before the specified node: "; cin >> nn->data;

    // If the node to be inserted before is the head node
    if (prev == NULL){
        nn->link = head;
        head = nn;
    }
    else{
        prev->link = nn;
        nn->link = temp;
    }
    
    cout << "Node added before the specified node!" << endl;
}

int main()
{
    List lst;
    int n;
    cout << "Enter no. of nodes: ";
    cin >> n;
    int key;
    cout << "Enter before which node to be add new node: ";
    cin >> key;
    lst.create(n);
    lst.display();
    lst.addBefore(key);
    lst.display();
}