#include<iostream>
using namespace std;

int main(){
    // const int size=10;
    // int a[size],n;
    // cout <<"Enter the number of elements: "; cin>>n;
    // cout <<"Enter elements: ";
    // for(int i=0 ; i<n ;i++){
    //     cin >> a[i];
    // }

    //Dyanamic array
    int n,*a;
    cout << "Enter no. of elements: ";cin>>n;
    a = new int[n];
    cout << "Enter elements: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int s=0,avg=0;
    for (int i = 0; i < n; i++)
    {
        s = s+a[i];
        avg = s/n;
    }
    cout <<"Average is: " << avg;
}