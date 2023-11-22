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

        // Function to create a linked list in reverse order
        void create()
        {
            int n, x;
            node *nn; // Pointer to the new node
            cout << "Enter no. of nodes: ";
            cin >> n; 
            for (int i = 0; i < n; i++)
            {
                cout << "Enter data: ";
                cin >> x;        // Getting data for each node from the user
                nn = new node;   // Creating a new node
                nn->data = x;    // Setting data for the new node
                nn->link = head; // Making the new node point to the current head of the list
                head = nn;       // Making the new node the new head of the list
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