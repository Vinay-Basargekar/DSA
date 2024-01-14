#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

struct node
{
    int data;
    node *link;
};

class Stack
{
    node *head;

public:
    Stack()
    {
        head = NULL;
    }

    void push(int x)
    {
        node *nn;
        nn = new node;
        if (nn == NULL)
        {
            cout << "Memory full";
            exit(0);
        }
        nn->data = x;
        nn->link = head;
        head = nn;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "No item to pop!";
            exit(0);
        }
        node *temp;
        temp = head;
        int y = temp->data;
        head = temp->link;
        delete temp;
        return y;
    }

    int isEmpty()
    {
        return head == NULL ? 1 : 0;
    }
};

int isoperand(char symb)
{
    return (symb >= 'A' && symb <= 'Z') ||
           (symb >= 'a' && symb <= 'z') ||
           (symb >= '0' && symb <= '9');
}

int digit(char symb)
{
    return (symb >= '0' && symb <= '9');
}

float evalpf(char postf[80])
{
    Stack s;
    int op1, op2, res;
    char symb;
    for (int i = (strlen(postf) - 1); i >= 0; i--)
    {
        symb = postf[i];
        if (isoperand(symb))
        {
            if (digit(symb))
            {
                s.push(symb - '0');
            }
            else
            {
                int x;
                cout << "Enter the value of " << symb << " :";
                cin >> x;
                s.push(x);
            }
        }
        else
        {
            op2 = s.pop();
            op1 = s.pop();
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
            default:
                cout << "Invalid";
                break;
            }
            s.push(res);
        }
    }
    return s.pop();
}
int main()
{
    char postf[80];
    cout << "Enter valid prefix expression: ";
    cin >> postf;
    float r = evalpf(postf);
    cout << "Result = " << r;
    return 0;
}