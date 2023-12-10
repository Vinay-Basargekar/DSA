#include<iostream>
using namespace std;

const int SIZE = 10;

class CQueue{
    int arr[SIZE];
    int r,f;
    public:
    CQueue(){
        f = 0;
        r = -1;
    }
    void insert(int x);
    int delitem();
    void dispq();
};

void CQueue::insert(int x){
    if(r==SIZE-1){
        cout <<"Q full";
        exit(0);
    }
    arr[++r] = x;
}

int CQueue::delitem(){
    if((r==-1 && f==0) || f>r){
        cout <<"Q empty!";
        exit(0);
    }
    // for(int i=0 ; i<r ;i++){
    //     arr[i] = arr[i+1];
    // }
    return(arr[f++]);
}

void CQueue::dispq()
{
    for(int i=f ; i<=r ; i++){
        cout <<arr[i]<<" ";
    }
}

int main(){
    CQueue q;
    q.insert(5);
    q.insert(6);
    q.insert(7);
    q.insert(8);
    q.delitem();
    q.dispq();
}