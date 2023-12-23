// Design and develop a Stack using Linked representation and write a menu driven C++ program to perform following operations.
// a) Input a valid postfix expression and evaluate it
// b) Input a valid prefix expression and evaluate

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

struct node
{
    float data;
    node *link;
};

class Stack
{
private:
    node *head;

public:
    Stack()
    {
        head = nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void push(float x)
    {
        node *nn = new node;
        if (nn == nullptr)
        {
            cout << "Stack is Full";
            exit(0);
        }
        nn->data = x;
        nn->link = head;
        head = nn;
    }

    float pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        node *temp = head;
        float y = temp->data;
        head = temp->link;
        delete temp;
        return y;
    }
};

int isOperand(char symb)
{
    return (symb >= 'a' && symb <= 'z') || (symb >= 'A' && symb <= 'Z') || (symb >= '0' && symb <= '9');
}

int isDigit(char symb)
{
    return (symb >= '0' && symb <= '9');
}

float evalPR(char pr[80])
{
    Stack s1;
    char symb;
    float op1, op2, res, x;
    for (int i = strlen(pr) - 1; i >= 0; i--)
    {
        symb = pr[i];
        if (isOperand(symb))
        {
            if (isDigit(symb))
            {
                s1.push(symb - '0');
            }
            else
            {
                float x;
                cout << "Enter value of " << symb << ": ";
                cin >> x;
                s1.push(x);
            }
        }
        else
        {
            op1 = s1.pop();
            op2 = s1.pop();
            switch (symb)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            case '$':
                res = pow(op1, op2);
                break;
            }
            s1.push(res);
        }
    }
    return s1.pop();
}

float evalPF(char pf[80])
{
    Stack s1;
    char symb;
    float op1, op2, res;
    for (int i = 0; pf[i] != '\0'; i++)
    {
        symb = pf[i];
        if (isOperand(symb))
        {
            if (isDigit(symb))
            {
                s1.push(symb - '0');
            }
            else
            {
                float x;
                cout << "Enter value for " << symb << ": ";
                cin >> x;
                s1.push(x);
            }
        }
        else
        {
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
                cout << "Invalid Choice";
            }
            s1.push(res);
        }
    }
    return s1.pop();
}

int main()
{
    int choice;
    while (true)
    {
        cout << "1. Evaluate Prefix Expression\n";
        cout << "2. Evaluate Postfix Expression\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            char pr[80];
            cout << "Enter valid prefix expression: ";
            cin >> pr;
            float r = evalPR(pr);
            cout << "Result = " << r << endl;
            break;
        }
        case 2:
        {
            char pf[80];
            cout << "Enter valid postfix expression: ";
            cin >> pf;
            float res = evalPF(pf);
            cout << "Result = " << res << endl;
            break;
        }
        case 3:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
