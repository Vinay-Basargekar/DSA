#include <iostream>
using namespace std;

const int MAX = 100;

class Stack
{
    string a[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(string x);
    string pop();
    void disp();
    int isEmpty();
    int full();
};

void Stack::push(string x)
{
    if (!full())
    {
        a[++top] = x;
    }
    else
    {
        cout << "Stack Overflow! Cannot push. Stack is full." << endl;
    }
}

string Stack::pop()
{
    if (!isEmpty())
    {
        return a[top--];
    }
    else
    {
        cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
        return "";
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

bool isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

string postfixToInfix(string postfix)
{
    Stack st;

    int len = postfix.size();
    for (int i = 0; i < len; i++)
    {
        if (isOperand(postfix[i]))
        {
            st.push(string(1, postfix[i]));
        }
        else
        {
            string operand1 = st.pop();
            string operand2 = st.pop();
            st.push("(" + operand2 + string(1, postfix[i]) + operand1 + ")");
        }
    }
    return st.pop();
}

int main()
{
    string postfix = "abc/-ad/e-*";
    string infix = postfixToInfix(postfix);
    cout << "Postfix expression : " << postfix << endl;
    cout << "Infix expression : " << infix << endl;

    return 0;
}
