#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};

class List{
    node *head;

public:
    // Constructor to initialize head pointer to NULL
    List() { head = NULL; }

    void create(int n)
    {
        node *nn,*prev;
        for (int i = 0; i < n; i++)
        {
            nn = new node;
            cout << "Enter data: ";
            cin >> nn ->data;
            nn->link = NULL;
            // If it's the first node being added, set it as head and continue
            if(i==0){
                head=nn;
                prev=nn;
                continue;
            }
            // Linking the current node to the previous one
            prev ->link=nn;
            prev = nn;
        }
    }
    void display()
    {
        node *temp;
        temp = head;
        cout << "Freshly created Linked list is: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
    }
};

int main()
{
    List lst;
    int n;
    cout << "No. of nodes: "; cin >> n;
    lst.create(n);
    lst.display();
}