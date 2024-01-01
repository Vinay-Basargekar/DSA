// Design and Develop a Linear queue using sequential representation having max size
// of 50 numbers with operations as insert/delete items to/from it. Write a menu driven
// C program to perform following operations.
// a) Issue a token number to customer(insert)
// b) Serve a Customer(delete)
// c) Display token numbers of Customers

#include<iostream>
using namespace std;
const int size = 50;
class Queue
{
    int items[size];
    int f, r;

public:
    Queue()
    {
        f = -1;
        r = -1;
    }
    bool isFull();
    bool isEmpty();
    void enqueue(int value);
    void delete_queue();
    void displayQueue();
};


bool Queue::isFull()
{
    return (r == size - 1);
}

bool Queue::isEmpty()
{
    return (f == -1 && r == -1);
}

void Queue::enqueue(int value)
{
    if (isFull())
    {
        cout << "Queue is full. Cannot insert." << endl;
        return;
    }
    else
    {
        if (isEmpty())
        {
            f = r = 0;
        }
        else
        {
            r++;
        }
        items[r] = value;
        cout << "Token number " << value << " issued to customer." << endl;
    }
}

void Queue::delete_queue()
{
    if (isEmpty())
    {
        cout << "Queue is empty. No customers to serve." << endl;
        return;
    }
    else
    {
        cout << "Token number " << items[f] << " served." << endl;
        if (f == r)
        {
            f = r = -1;
        }
        else
        {
            f++;
        }
    }
}

void Queue::displayQueue()
{
    if (isEmpty())
    {
        cout << "Queue is empty. No tokens to display." << endl;
        return;
    }
    else
    {
        cout << "Token numbers of customers in the queue: ";
        for (int i = f; i <= r; i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Queue q;
    int choice, token;
    do
    {
        cout << "\nEnter your choice:\n";
        cout << "1. Issue a token number to customer (Insert)\n";
        cout << "2. Serve a customer (Delete)\n";
        cout << "3. Display token numbers of customers\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter token number to issue: ";
            cin >> token;
            q.enqueue(token);
            break;
        case 2:
            q.delete_queue();
            break;
        case 3:
            q.displayQueue();
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);
    return 0;
}