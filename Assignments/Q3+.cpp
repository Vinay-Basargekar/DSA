//helloo
#include <iostream>
using namespace std;

const int SIZE = 50;

class CQueue
{
private:
    int a[SIZE];
    int r, f, count;

public:
    CQueue()
    {
        f = 0;
        r = -1;
        count = 0;
    }

    void insert(int data)
    {
        if (count == SIZE)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        if (r == SIZE - 1)
        {
            r = -1;
        }
        a[++r] = data;
        count++;
        cout << "Token " << data << " issued successfully" << endl;
    }

    int delToken()
    {
        if (count == 0)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int servedToken = a[f++];
        if (f == SIZE)
        {
            f = 0;
        }
        count--;
        cout << "Token " << servedToken << " served" << endl;
        return servedToken;
    }

    void dispToken()
    {
        if (count == 0)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        int i = f;
        int n = count;
        while (n > 0)
        {
            if (i == SIZE)
            {
                i = 0;
            }
            cout << a[i] << " ";
            i++;
            n--;
        }
        cout << endl;
    }
};

int main()
{
    CQueue cq;
    int ch, data;
    while (true)
    {
        cout << "\n1. Issue Token Number To Customer";
        cout << "\n2. Serve a Customer";
        cout << "\n3. Display Token Numbers Of Customer";
        cout << "\n4. Exit";
        cout << "\nEnter your choice:";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter Token Number To Issue: ";
            cin >> data;
            cq.insert(data);
            break;

        case 2:
            cq.delToken();
            break;

        case 3:
            cout << "Tokens in Queue: ";
            cq.dispToken();
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << "Invalid Choice" << endl;
        }
    }
    return 0;
}
