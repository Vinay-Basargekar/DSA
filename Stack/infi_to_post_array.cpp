#include <iostream>
using namespace std;

const int MAX = 100;

class Stack
{
    int a[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(int x);
    int pop();
    void disp();
    int isEmpty();
    int full();
};

void Stack::push(int x)
{
    if (!full())
    {
        a[++top] = x;
    }
    else
    {
        cout << "Stack Overflow! Cannot push . Stack is full." << endl;
    }
}

int Stack::pop()
{
    if (!isEmpty())
    {
        return a[top--];
    }
    else
    {
        cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
        return -1;
    }
}

int Stack::full()
{
    return top == MAX - 1 ? 1 : 0;
}

int Stack::isEmpty()
{
    return top == -1 ? 1 : 0;
}

void Stack::disp()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; --i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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
    int i, j = 0;
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
                int flag = 0;
                st_symb = s1.pop();
                while (prcd(st_symb) > prcd(symb))
                {
                    postf[j++] = st_symb;
                    if (!s1.isEmpty())
                        st_symb = s1.pop();
                    else
                        flag = 1;
                    break;
                }
                if (flag == 1)
                {
                    s1.push(symb);
                }
                else
                {
                    s1.push(st_symb);
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

int main()
{
    char infi[80], postf[80];
    cout << "Enter Valid Infix Expression: ";
    cin >> infi;
    convert(infi, postf);
    cout << "The postfix is: " << postf;
}