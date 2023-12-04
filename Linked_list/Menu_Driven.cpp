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
    // Constructor to initialize head pointer to NULL
    List() { head = NULL; }

    void create(int n){
        node *nn, *prev;
        for (int i = 0; i < n; i++)
        {
            nn = new node;
            cout << "Enter Data: ";
            cin >> nn->data;
            nn->link = NULL;
            // If it's the first node being added, set it as head and continue
            if (i == 0){
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
        cout << "Linked List: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
    }
    void frontEndNode();
    void rearEndNode();
    void delFrontEnd();
    void delRearEnd();
    void delSpecified(int key);
    void addAfter(int key);
    void addBefore(int key);
};

void List::frontEndNode(){
    node* nn;
    nn = new node;
    cout <<"Enter data to add at front: ";
    if (nn == NULL){
        cout << "Memory not available!";
        exit(0);
    }
    cin >> nn->data;
    nn->link = head;
    head = nn;
}

void List::rearEndNode(){
    node *nn;
    nn = new node;
    cout << "Enter data to add at rear: ";
    if (nn == NULL){
        cout << "Memory not available!";
        exit(0);
    }
    cin >> nn->data;
    nn->link = NULL;
    if (head == NULL){
        head = nn;
        return;
    }
    node* t=head;
    while(t->link != NULL){
        t = t->link;
    }
    t->link = nn;
}

void List::delFrontEnd(){
    node* temp;
    if (head == NULL){
        cout << "Empty List!";
        exit(0);
    }
    temp = head;
    head = temp->link;
    delete temp;
    cout << endl;
    cout << "front Node deleted!" << endl;
}

void List::delRearEnd(){
    node *temp, *prev;
    temp = head;
    prev = NULL;
    // Check if the list is empty
    if (temp == NULL){
        cout << "Empty List! Cannot delete." << endl;
        return;
    }
    while (temp->link != NULL){
        prev = temp;
        temp = temp->link;
    }
    prev->link = NULL;
    delete temp;
    cout << endl;
    cout << "Rear Node deleted!" << endl;
}

void List::delSpecified(int key){
    node *temp = head;
    node *prev=NULL;
    // If the list is empty
    if (temp == NULL)
    {
        cout << "Empty List! Cannot delete." << endl;
        return;
    }
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            break;
        }
        prev = temp;
        temp = temp->link;
    }
    prev->link = temp->link;
    delete temp;
    cout << "Node deleted!" << endl;
}

void List::addAfter(int key){
    node *temp, *nn;
    temp = head;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->link;
    }
    if (temp == NULL)
    {
        cout << "Specified node not found" << endl;
    }
    nn = new node;
    if (nn == NULL)
    {
        cout << "memory full";
        exit(0);
    }
    cout << endl;
    cout << "Enter data to be added: ";
    cin >> nn->data;
    nn->link = temp->link;
    temp->link = nn;
    cout << "Node added after!" << endl;
}

void List::addBefore(int key){
    node *temp = head;
    node *prev = NULL;

    // Search for the specified node key and keep track of the previous node
    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->link;
    }

    // If the specified node is not found
    if (temp == NULL){
        cout << "Specified node not found" << endl;
        exit(0);
    }
    node *nn = new node;
    if (nn == NULL){
        cout << "Memory full" << endl;
        exit(0);
    }
    cout << endl;
    cout << "Enter data to be added before the specified node: ";
    cin >> nn->data;

    // If the node to be inserted before is the head node
    if (prev == NULL){
        nn->link = head;
        head = nn;
    }
    else{
        prev->link = nn;
        nn->link = temp;
    }

    cout << "Node added before the specified node!" << endl;
}

int main()
{
    List lst;
    int n, op;
    cout << "Enter No. Of nodes: ";
    cin >> n;
    lst.create(n);
    lst.display();

    do{
        cout << endl;
        cout << "Operations" << endl;
        cout << "1. Enter front end node" << endl;
        cout << "2. Enter rear end node" << endl;
        cout << "3. Delete a front end node" << endl;
        cout << "4. Delete a rear end node" << endl;
        cout << "5. Delete a specified place node" << endl;
        cout << "6. Add After a node" << endl;
        cout << "7. Add Before a node" << endl;
        cout << "Enter your choice (1-8, 8 to exit): ";
        cin >> op;

        switch (op)
        {
        case 1:
            lst.frontEndNode();
            break;
        case 2:
            lst.rearEndNode();
            break;
        case 3:
            lst.delFrontEnd();
            break;
        case 4:
            lst.delRearEnd();
            break;
        case 5:
            int key;
            cout << "Enter Node to delete: ";
            cin >> key;
            lst.delSpecified(key);
            break;
        case 6:
            cout << "Enter after which node to add a new node: ";
            cin >> key;
            lst.addAfter(key);
            break;
        case 7:
            cout << "Enter before which node to add a new node: ";
            cin >> key;
            lst.addBefore(key);
            break;
        case 8:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid option! Please enter a valid choice." << endl;
            break;
        }
        lst.display();
    }while(op != 8);
    return 0;
}
