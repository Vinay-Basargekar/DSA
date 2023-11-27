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
    void create(int n){
        node *nn,*prev;
        for (int i = 0; i < n; i++)
        {   
            nn = new node;
            cout <<"Enter data: "; cin >> nn->data;
            nn -> link = NULL;
            if(i==0){
                head = nn;
                prev = nn;
                continue;
            }
            prev -> link=nn;
            prev = nn;
        }
    }
    void display(){
        node *t=head;
        cout <<"Linked list is: ";
        while(t!=NULL){
            cout << t->data <<" ";
            t= t->link;
        }
    }
    void delFront();    
};

void List :: delFront(){
    node *temp;
    if(head == NULL){
        cout << "Empty List!";
        exit(0);
    }
    temp = head;
    head = head->link;
    delete temp;
    cout << endl;
    cout << "front Node deleted!"<<endl;
}

int main(){
    List lst;
    int n;
    cout <<"Enter no. of nodes: ";
    cin >> n;
    lst.create(n);
    lst.display();
    lst.delFront();
    lst.display();
}