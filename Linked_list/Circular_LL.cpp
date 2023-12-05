#include<iostream>
using namespace std;

struct node{
    int data;
    node* link;
};

class List{
    node* head;
    public:
    List(){
        head = NULL;
    }

    node* nn,*last;
    void create(int n){
        for(int i=0 ; i<n ; i++){
            nn = new node;
            cout <<"Enter data: ";
            cin >> nn->data;
            nn->link=NULL;
            if(i==0){
                last = nn;
                nn->link = nn;
                continue;
            }
            nn->link = last->link;
            last->link = nn;
            last = nn;
        }
    }
    void display(){
        node* temp;
        temp = last->link;
        cout <<"The circular Linked list is: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->link;
        } while (temp != last->link);
    }
};

int
main()
{
    List lst;
    int n;
    cout << "No. of nodes: ";
    cin >> n;
    lst.create(n);
    lst.display();
}