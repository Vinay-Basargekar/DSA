#include<iostream>
using namespace std;

struct node{
    int data;
    node* link;
};

class List{
    node* head;

    public:
        List(){ head = NULL;}

        void create(){
            int n,i,x;
            node *nn;
            cout << "Enter no. of nodes: ";
            cin >> n;
            cout << "Enter data: "; 
            for(i=0 ; i<n ; i++){
                cin >> x;
                nn = new node;
                nn -> data = x;
                nn -> link = head;
                head = nn;
            }
        }
        void display(){
            node* temp;
            temp = head;
            cout << "Reversed List is: ";
            while(temp != NULL){
                cout << temp -> data << " ";
                temp = temp ->link;
            }
        }
};

int main(){
    List lst;
    lst.create();
    lst.display();
}