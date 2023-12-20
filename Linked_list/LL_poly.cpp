#include<iostream>
using namespace std;

struct node{
    float coefficient;
    int exponent;
    node* link;
};

class List{
    node* head;
    public:
    List(){
        head = NULL;
    }
    void create(int n){
        node* nn,*prev;
        for (int i = 0; i < n; i++)
        {
            nn = new node;
            cout << "Enter Coefficient: ";
            cin >> nn->coefficient;
            cout <<"Enter exponent: ";
            cin >> nn->exponent;
            nn->link = NULL;
            // If it's the first node being added, set it as head and continue
            if (i == 0)
            {
                head = nn;
                prev = nn;
                continue;
            }
            // Linking the current node to the previous one
            prev->link = nn;
            prev = nn;
        }
    }
    void display()
    {
        node *temp;
        temp = head;
        cout << "Polynomial: ";
        while (temp != NULL){
            cout << temp->coefficient << "x^" << temp->exponent;
            temp = temp->link;
            if (temp != NULL)
            {
                cout << " + ";
            }
        }
        cout << endl;
    }
};

int main(){
    List lst;
    int n;
    cout << "No. of nodes: ";
    cin >> n;
    lst.create(n);
    lst.display();
}