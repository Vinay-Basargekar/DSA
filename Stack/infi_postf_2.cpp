#include <iostream>
#include <cmath>
using namespace std;

struct node
{
    float data;
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
    void push(float x);
    float pop();
    void disp();
    int isEmpty();
};

int Stack::isEmpty()
{
    return head == NULL ? 1 : 0;
}

void Stack::push(float x)
{
    node *nn = new node;
    if (nn == NULL)
    {
        cout << "Stack Full";
        exit(0);
    }
    nn->data = x;
    nn->link = head;
    head = nn;
}

float Stack::pop()
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

int isOperand(char symb)
{
    return (symb >= 'a' && symb <= 'z') || (symb >= 'A' && symb <= 'Z') || (symb >= '0' && symb <= '9');
}

int prcd(char ch)
{
    if (ch == '$')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/' || ch == '%')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void convert(char infi[80], char postf[80])
{
    Stack s1;
    int i, j;
    char symb, st_symb;
    for (i = 0; infi[i] != '\0'; i++)
    {
        symb = infi[i];
        if (isOperand(symb))
        {
            postf[j++] = symb;
        }
        else if (symb == '(')
        {
            s1.push(symb);
        }
        else if (symb == '$' || symb == '*' || symb == '/' || symb == '+' || symb == '-')
        {
            if (s1.isEmpty())
            {
                s1.push(symb);
            }
            else
            {
                st_symb = s1.pop();
                while (prcd(st_symb) > prcd(symb))
                {
                    postf[j++] = st_symb;
                    if (!s1.isEmpty())
                        st_symb = s1.pop();
                    else
                        break;
                }
                if(prcd(st_symb) < prcd(symb)){
                    s1.push(st_symb);
                    s1.push(symb);
                }
                else{
                    s1.push(symb);
                }
            }
        }
        else if (symb == ')')
        {
            st_symb = s1.pop();
            while (st_symb != '(')
            {
                postf[j++] = st_symb;
                if (!s1.isEmpty())
                {
                    st_symb = s1.pop();
                }
            }
        }
    }
    while (!s1.isEmpty())
    {
        postf[j++] = s1.pop();
    }
    postf[j] = '\0';
}

int main(){
    char infi[80], postf[80];
    cout << "Enter Valid Infix Expression: ";
    cin >> infi;
    convert(infi, postf);
    cout << "The postfix is: " << postf;
}