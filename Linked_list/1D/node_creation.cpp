#include <iostream>
#include<vector>
using namespace std;

// Create a Node structure
class Node{
    public:
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

// function to get head using array
Node* ConvertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1 ; i<sizeof(arr)/sizeof(arr[0]) ; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main(){

    // create a ptr pointing to node created
    Node* x = new Node(2,NULL);
    // cout << x->data << endl;
    // cout << x->next << endl;

    // Convert Array to LL
    vector<int> arr = {1,2,3,4,5};
    Node* head = ConvertArr2LL(arr);
    // cout << head->data << endl;

    // traversal in Linked List
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp-> next;
    }
    return 0;
}