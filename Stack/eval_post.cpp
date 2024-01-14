// WAP to Evaluate a given post fix using stack implementation with LL

#include <iostream>
#include <cmath>
using namespace std;

struct node{
    float data;
    node *link;
};

class Stack{
    node *head;

public:
    Stack(){
        head = NULL;
    }
    void push(float x);
    float pop();
    void disp();
    int isEmpty();
};

int Stack::isEmpty(){
    return head == NULL ? 1 : 0;
}

void Stack::push(float x){
    node *nn;
    nn = new node;
    if (nn == NULL){
        cout << "Stack Full";
        exit(0);
    }
    nn->data = x;
    nn->link = head;
    head = nn;
}

float Stack::pop(){
    if (isEmpty()){
        cout << "Stack is empty";
        exit(0);
    }
    node *temp = head;
    float y = temp->data;
    head = temp->link;
    delete temp;
    return y;
}

int isOperand(char symb){
    return (symb >= 'a' && symb <= 'z') || (symb >= 'A' && symb <= 'Z') || (symb >= '0' && symb <= '9');
}

int isDigit(char symb){
    return (symb >= '0' && symb <= '9');
}

float eval(char pf[80]){
    Stack s1;
    char symb;
    float op1, op2, res;
    for (int i = 0; pf[i] != '\0'; i++){
        symb = pf[i];
        if (isOperand(symb)){
            if (isDigit(symb)){
                s1.push(symb - '0');
            }
            else{
                float x;
                cout << "Enter value for " << symb << ": ";
                cin >> x;
                s1.push(x);
            }
        }
        else{
            op2 = s1.pop();
            op1 = s1.pop();
            switch (symb)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '$':
                res = pow(op1, op2);
                break;
            default:
                cout << "Invalid operator";
            }
            s1.push(res);
        }
    }
    return s1.pop();
}

int main()
{
    char post[80];
    cout << "Enter valid postfix expression: ";
    cin >> post;
    float r = eval(post);
    cout << "Result = " << r;
    return 0;
}
