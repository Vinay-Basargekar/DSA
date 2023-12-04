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
    List(){
        head = NULL;
    }

    void create(int n){
        node *nn, *prev;
        for (int i = 0; i < n; i++){
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

    void display(){
        node *temp;
        temp = head;
        cout << "Linked list is: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }

    void addNode(int x){
        node *nn, *temp;
        nn = new node;
        if (nn == NULL){
            cout << "Memory full";
            exit(0);
        }
        nn->data = x;
        nn->link = NULL;
        if (head == NULL){
            head = nn;
            return;
        }
        temp = head;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = nn;
    }

    List merge(List lst2){
        node *t1 = head, *t2 = lst2.head;
        List tlist;

        while (t1 != NULL && t2 != NULL){
            if (t1->data < t2->data){
                tlist.addNode(t1->data);
                t1 = t1->link;
            }
            else{
                tlist.addNode(t2->data);
                t2 = t2->link;
            }
        }

        while (t1 != NULL){
            tlist.addNode(t1->data);
            t1 = t1->link;
        }

        while (t2 != NULL){
            tlist.addNode(t2->data);
            t2 = t2->link;
        }

        return tlist;
    }
};

int main()
{
    List lst1, lst2, lst3;
    int n;
    cout << "Enter no. of nodes for lst1: ";
    cin >> n;
    lst1.create(n);

    cout << "Enter no. of nodes for lst2: ";
    cin >> n;
    lst2.create(n);

    lst3 = lst1.merge(lst2);

    cout << "Merged Linked List: ";
    lst3.display();

    return 0;
}
