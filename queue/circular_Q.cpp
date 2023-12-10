#include<iostream>
using namespace std;

const int SIZE=5;

class CQueue{
    int arr[SIZE];
    int r,f,count;
    public:
    CQueue(){
        f = 0; r = -1; count = 0;
    }
    void insert(int x);
    int delitem();
    void dispq();
};

void CQueue::insert(int x){
    if(count == SIZE){
        cout <<"Q full";
        exit(0);
    }
    // if(r==SIZE-1){
    //     r = 0;
    // }
    // arr[++r]=x;
    // count++;
    if (r == SIZE - 1){
        r = 0; // Wrap around to the beginning of the array
    }
    else{
        r++;
    }
    arr[r] = x;
    count++;
}

int CQueue::delitem(){
    if(count == 0){
        cout <<"Q Empty";
        exit(0);
    }
    int y;
    if(f==SIZE){
        f=0;
    }
    y=arr[f++];
    count--;
    return y;
}

// void CQueue::dispq()
// {
//     for (int i = f; i <= r; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout<<endl;
//     cout << count;
// }

void CQueue::dispq()
{
    if (count == 0)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    int i = f;
    do
    {
        cout << arr[i] << " ";
        i = (i + 1) % SIZE;
    } while (i != (r + 1) % SIZE); // Loop through the circular queue

    cout << endl;
    cout << "Count: " << count << endl;
}

int main(){
    CQueue q;
    q.insert(1);
    q.insert(2);
    q.insert(3);
    q.insert(4);
    q.insert(4);
    q.delitem();
    q.delitem();
    q.insert(4);
    q.insert(4);
    q.dispq();
}