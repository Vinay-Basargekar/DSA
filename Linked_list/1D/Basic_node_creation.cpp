#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data,Node* next){
        data = data;
        next = next;
    }

    Node(int data){
        data = data;
        next = nullptr;
    }
};

int main(){
    Node* x = new Node(2,NULL);
    // Node* y = &x;

    cout << x->data << endl;
    cout << x->next << endl;
    return 0;
}