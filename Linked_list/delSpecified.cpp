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
    void delSpecified(int key);
};

void List ::delSpecified(int key)
{
    node* temp = head;
    node* prev;
    // If the list is empty
    if (temp == NULL)
    {
        cout << "Empty List! Cannot delete." << endl;
        return;
    }
    while (temp != NULL)
    {
        if(temp -> data==key){
            break;
        }
        prev = temp;
        temp = temp ->link;
    }
    prev->link = temp->link;
    delete temp;
    cout << endl;
    cout << "Node deleted!" << endl;
}

int main()
{
    List lst;
    int n;
    cout << "Enter no. of nodes: ";
    cin >> n;
    int key;
    cout <<"Enter the node to be deleted: ";
    cin >> key;
    lst.create(n);
    lst.display();
    lst.delSpecified(key);
    lst.display();
}