#include <iostream>
using namespace std;

const int MAX = 100;

class Stack{
    int a[MAX];
    int top;
    
    public:
        Stack(){ 
            top = -1; 
        }
        void push(int x);
        int pop();
        void disp();
        int empty();
        int full();
};

void Stack::push(int x){
    if (!full()){
        a[++top] = x;
        // cout << "Pushed " << x << " into the stack." << endl;
    }else{
        cout << "Stack Overflow! Cannot push " << x << ". Stack is full." << endl;
    }
}

int Stack::pop(){
    if (!empty()){
        return a[top--];
    }else{
        cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
        return -1;
    }
}

int Stack::full(){
    return top == MAX - 1 ? 1 : 0;
}

int Stack::empty(){
    return top == -1 ? 1 : 0;
}

void Stack::disp(){
    if (empty()){
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; --i){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    Stack stack;
    int choice, item;

    stack.push(4);
    stack.push(1);

    stack.disp();

    // do{
    //     cout << "\n---------------------";
    //     cout << "\nStack Implementation";
    //     cout << "\n---------------------";
    //     cout << "\n1.Push";
    //     cout << "\n2.Pop";
    //     cout << "\n3.Display";
    //     cout << "\n4.Exit";
    //     cout << "\nEnter your choice: ";
    //     cin >> choice;

    //     switch (choice){
    //     case 1:
    //         cout << "\nEnter item to push: ";
    //         cin >> item;
    //         stack.push(item);
    //         break;
    //     case 2:
    //         item = stack.pop();
    //         if (item != -1)
    //         {
    //             cout << "\nPopped item is: " << item << endl;
    //         }
    //         break;
    //     case 3:
    //         stack.disp();
    //         break;
    //     case 4:
    //         cout << "\nExiting...";
    //         break;
    //     default:
    //         cout << "\nInvalid choice!";
    //     }
    // } while (choice != 4);

    return 0;
}
