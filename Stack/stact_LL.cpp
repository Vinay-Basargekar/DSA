#include<iostream>
using namespace std;

struct node{
    int data;
    node* link;
};

class Stack{
    node* head;
    public:
    Stack(){
        head = NULL;
    }
    void push(int x);
    int pop();
    void disp();
    int isEmpty();
};

int Stack::isEmpty(){
    if(head == NULL){
        return 1;
    }
    else
        return 0;
}

void Stack::push(int x){
    node *nn;
    nn = new node;
    if(nn == NULL){
        cout << "Stack Full";
        exit(0);
    }
    nn->data=x;
    nn->link = head;
    head = nn;
    cout << "Item pushed";
}

int Stack::pop(){
    node* temp;
    if(isEmpty()){
        cout <<"Stack is empty";
        exit(0);
    }
    temp = head;
    int y=temp->data;
    head = temp->link;
    delete temp;
    return y;
}

void Stack::disp(){
    node* t= head;
    while(t!=NULL){
        cout << t->data <<" ";
        t=t->link;
    }
}

int main()
{
    Stack stack;
    int choice, item;

    do
    {
        cout << "\n---------------------";
        cout << "\nStack Implementation";
        cout << "\n---------------------";
        cout << "\n1.Push";
        cout << "\n2.Pop";
        cout << "\n3.Display";
        cout << "\n4.Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter item to push: ";
            cin >> item;
            stack.push(item);
            break;
        case 2:
            item = stack.pop();
            cout << "\nPopped item is: " << item;
            break;
        case 3:
            cout << "\nStack elements: ";
            stack.disp();
            break;
        case 4:
            cout << "\nExiting...";
            exit(0);
        default:
            cout << "\nInvalid choice!";
        }
    } while (choice != 4);

    return 0;
}
