#include<iostream>
using namespace std;

void merge(int p[],int q[],int n){
    int c[2*n];
    for(int i=0 ; i<n ;i++){
        c[i] = p[i];
        c[i+n] = q[i];
    }
    for(int i = 0 ; i<2*n ; i++){
        cout << c[i] <<" ";
    }
}

int main(){
    int n;
    cout << "Enter the size of array: ", cin >> n;
    int *p, *q;
    p = new int[n];
    q = new int[n];
    cout << "Enter array 1: ";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout << "Enter array 2: ";
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    merge(p,q,n);
}