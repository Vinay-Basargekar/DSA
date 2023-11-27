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
        node* nn;
        node* prev;
        for (int i = 0; i < n; i++)
        {
            nn = new node;
            cout << "Enter data: ";
            cin >> nn ->data;
            if(i==0){
                head = nn;
                prev = head;
                continue;
            }
            prev ->link=nn;
            prev = nn;
        }
    }
    void display(){
        node *temp;
        temp = head;
        cout << "Linked list is: ";
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->link;
        }
    }
    void delRearEnd();
};

void List :: delRearEnd(){
    node* temp,*prev;
    temp = head;
    prev = NULL;
    // Check if the list is empty
    if (temp == NULL)
    {
        cout << "Empty List! Cannot delete." << endl;
        return;
    }
    while (temp ->link != NULL){
        prev = temp;
        temp = temp->link;
    }
    prev->link=NULL;
    delete temp;
    cout << endl;
    cout << "Rear Node deleted!" << endl;
}


int main(){
    List lst;
    int n;
    cout << "Enter no. of nodes: ";
    cin >> n;
    lst.create(n);
    lst.display();
    lst.delRearEnd();
    lst.display();
}