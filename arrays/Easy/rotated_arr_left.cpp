#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin >> k;
    k = k % n;
    int temp[n];
    for(int i=0 ; i<n ; i++){
        temp[(i-k+n) % n] = arr[i];
    }
    for(int i=0 ; i<n ; i++){
        cout << temp[i];
    }
    return 0;
}