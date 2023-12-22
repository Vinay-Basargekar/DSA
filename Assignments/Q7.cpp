// Design and develop a Stack using sequential representation and write a menu driven C++ program to perform following operations.
// a) Input a valid infix expression and convert it to postfix expression.
// b) Input a valid infix expression and convert it to prefix expression.

#include <iostream>
using namespace std;

const int MAX = 100;

class Stack
{
    char a[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(char x)
    {
        if (!full())
        {
            a[++top] = x;
        }
        else
        {
            cout << "Stack Overflow! Cannot push " << x << ". Stack is full." << endl;
        }
    }

    char pop()
    {
        if (!empty())
        {
            return a[top--];
        }
        else
        {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return -1;
        }
    }

    int full()
    {
        return top == MAX - 1 ? 1 : 0;
    }

    int empty()
    {
        return top == -1 ? 1 : 0;
    }
};

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
            if (s1.empty())
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
                    if (!s1.empty())
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
                if (!s1.empty())
                {
                    st_symb = s1.pop();
                }
            }
        }
    }
    while (!s1.empty())
    {
        postf[j++] = s1.pop();
    }
    postf[j] = '\0';
}

void reverseString(char str[])
{
    int len = strlen(str);
    int start = 0, end = len - 1;
    while (start < end)
    {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

void infixToPrefix(char infi[80], char pref[80])
{
    reverseString(infi);

    for (int i = 0; infi[i] != '\0'; i++)
    {
        if (infi[i] == '(')
        {
            infi[i] = ')';
        }
        else if (infi[i] == ')')
        {
            infi[i] = '(';
        }
    }

    char postf[80];
    convert(infi, postf);
    reverseString(postf);
    strcpy(pref, postf);
}

int main()
{
    Stack st;
    int choice;
    do
    {
        cout << "\n---------------------";
        cout << "\nStack operations";
        cout << "\n---------------------";
        cout << "\n1.Infix to Postfix";
        cout << "\n2.Infix to Prefix";
        cout << "\n4.Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            char infi[80], postf[80];
            cout << "Enter Valid Infix Expression: ";
            cin >> infi;
            convert(infi, postf);
            cout << "The postfix is: " << postf;
            break;
        case 2:
            char infi2[80], pref[80];
            cout << "Enter Valid Infix Expression: ";
            cin >> infi2;
            infixToPrefix(infi2, pref);
            cout << "The Prefix is: " << pref;
            break;
        case 4:
            cout << "\nExiting...";
            break;
        default:
            cout << "\nInvalid choice!";
        }
    } while (choice != 4);
    return 0;
}
