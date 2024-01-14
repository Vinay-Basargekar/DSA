#include <iostream>
using namespace std;

const int SIZE = 3;

class CQueue
{
    int arr[SIZE], rear, front, count;

public:
    CQueue()
    {
        rear = -1;
        front = 0;
        count = 0;
    }

    void insert(int x)
    {
        if (count == SIZE)
        {
            cout << "Full queue" << endl;
        }
        else
        {
            if (rear == SIZE - 1)
            {
                rear = -1;
            }
            arr[++rear] = x;
            count++;
        }
    }

    int delitem()
    {
        if (count == 0)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        if (front == SIZE)
        {
            front = 0;
        }
        int y = arr[front++];
        count--;
        return y;
    }

    void display()
    {
        if (count == 0)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            int i = front;
            int n = count;
            while (n > 0)
            {
                if (i == SIZE)
                {
                    i = 0;
                }
                cout << arr[i] << " ";
                i++;
                n--;
            }
            cout << endl;
        }
    }

    int isempty()
    {
        return (count == 0) ? 1 : 0;
    }
};

int main()
{
    CQueue q;
    int ch, data;
    while (true)
    {
        cout << "\n---------------------";
        cout << "\nQueue operations";
        cout << "\n---------------------";
        cout << "\n1. Insert an element";
        cout << "\n2. Delete an element";
        cout << "\n3. Display the queue";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the element to insert: ";
            cin >> data;
            q.insert(data);
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
            exit(0);

        default:
            cout << "\nInvalid Choice" << endl;
        }
    }
    return 0;
}
