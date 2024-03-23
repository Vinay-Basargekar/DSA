#include <iostream>
using namespace std;

const int SIZE = 5;

class Queue
{

    int arr[SIZE], rear, front;

public:
    Queue()
    {
        rear = -1;
        front = 0;
    }

    int isempty()
    {
        return (rear == -1 || front > rear) ? 1 : 0;
    }

    void insert(int x)
    {
        if (rear == SIZE - 1)
        {
            cout << "Full queue" << endl;
        }
        else
        {
            ++rear;
            arr[rear] = x;
        }
    }

    int delitem()
    {
        if (isempty())
        {
            cout << "queue empty" << endl;
            exit(0);
        }
        return (arr[front++]);
    }

    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Queue q;

    int choice, item;

    do
    {
        cout << "\n---------------------";
        cout << "\nQueue operations";
        cout << "\n---------------------";
        cout << "\n1. Insert an element";
        cout << "\n2. Delete an element";
        cout << "\n3. Display the queue";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element to insert: ";
            cin >> item;
            q.insert(item);
            break;
        case 2:
            if (!q.isempty())
            {
                int deletedItem = q.delitem();
                cout << "Deleted item: " << deletedItem << endl;
            }
            else
            {
                cout << "Queue is empty. Cannot delete." << endl;
            }
            break;
        case 3:
            cout << "Current Queue: ";
            q.display();
            cout << endl;
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
